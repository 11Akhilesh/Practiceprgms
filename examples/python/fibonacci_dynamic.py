#!/usr/bin/env python3
from functools import lru_cache

@lru_cache(maxsize=None)
def memoized_fib(n):
    if n < 2:
        return n
    return memoized_fib(n - 1) + memoized_fib(n - 2)

if __name__ == "__main__":
    for i in range(15):
        print(f"fib({i}) = {memoized_fib(i)}")
