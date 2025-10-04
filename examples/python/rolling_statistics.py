#!/usr/bin/env python3
from collections import deque

class RollingStats:  # Maintains rolling mean and variance
    def __init__(self, window_size):
        self.window = deque(maxlen=window_size)
        self._sum = 0.0
        self._sum_sq = 0.0

    def add(self, value):
        if len(self.window) == self.window.maxlen:
            dropped = self.window.popleft()
            self._sum -= dropped
            self._sum_sq -= dropped * dropped
        self.window.append(value)
        self._sum += value
        self._sum_sq += value * value

    def mean(self):
        if not self.window:
            return 0.0
        return self._sum / len(self.window)

    def variance(self):
        n = len(self.window)
        if n < 2:
            return 0.0
        mean = self.mean()
        return (self._sum_sq / n) - mean * mean

if __name__ == "__main__":
    stats = RollingStats(window_size=5)
    for number in range(1, 11):
        stats.add(number)
        print(f"Added {number}; mean={stats.mean():.2f}, variance={stats.variance():.2f}")
