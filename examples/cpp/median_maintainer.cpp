#include <functional>
#include <iostream>
#include <queue>

class MedianMaintainer {
public:
    void insert(int value) {
        if (low.empty() || value <= low.top()) {
            low.push(value);
        } else {
            high.push(value);
        }
        rebalance();
    }

    double median() const {
        if (low.size() == high.size()) {
            return (low.top() + high.top()) / 2.0;
        }
        return low.size() > high.size() ? low.top() : high.top();
    }

private:
    void rebalance() {
        if (low.size() > high.size() + 1) {
            high.push(low.top());
            low.pop();
        } else if (high.size() > low.size() + 1) {
            low.push(high.top());
            high.pop();
        }
    }

    std::priority_queue<int> low;
    std::priority_queue<int, std::vector<int>, std::greater<int>> high;
};

int main() {
    MedianMaintainer maintainer;
    for (int value : {10, 4, 6, 8, 15, 3}) {
        maintainer.insert(value);
        std::cout << "Median: " << maintainer.median() << '\n';
    }
}
