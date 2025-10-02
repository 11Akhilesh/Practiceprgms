#!/usr/bin/env python3
import time

class TokenBucket:  # Simple token bucket rate limiter
    def __init__(self, rate_per_second, capacity):
        self.rate = rate_per_second
        self.capacity = capacity
        self.tokens = float(capacity)
        self.timestamp = time.monotonic()

    def consume(self, amount=1):
        now = time.monotonic()
        elapsed = now - self.timestamp
        self.timestamp = now
        self.tokens = min(self.capacity, self.tokens + elapsed * self.rate)

        if self.tokens >= amount:
            self.tokens -= amount
            return True
        return False

if __name__ == "__main__":
    bucket = TokenBucket(rate_per_second=5, capacity=10)
    granted = 0
    start = time.monotonic()
    while time.monotonic() - start < 3:
        if bucket.consume():
            granted += 1
        time.sleep(0.05)
    print(f"Granted {granted} tokens in 3 seconds")
