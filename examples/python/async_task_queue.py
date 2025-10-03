#!/usr/bin/env python3
import asyncio
import random

class AsyncTaskQueue:  # Controls concurrency for coroutines
    def __init__(self, concurrency):
        self.semaphore = asyncio.Semaphore(concurrency)

    async def run(self, coro):
        async with self.semaphore:
            return await coro

async def worker(name, duration):
    await asyncio.sleep(duration)
    return f"{name} finished in {duration:.2f}s"

async def main():
    queue = AsyncTaskQueue(concurrency=3)
    tasks = [
        asyncio.create_task(queue.run(worker(f"task-{i}", random.uniform(0.1, 0.6))))
        for i in range(10)
    ]
    for task in asyncio.as_completed(tasks):
        print(await task)

if __name__ == "__main__":
    asyncio.run(main())
