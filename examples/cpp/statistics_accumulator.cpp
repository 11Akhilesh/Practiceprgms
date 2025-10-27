#include <iostream>

class StatisticsAccumulator {
public:
    void add(double value) {
        ++count;
        double delta = value - mean;
        mean += delta / count;
        double delta2 = value - mean;
        m2 += delta * delta2;
    }

    double average() const { return count ? mean : 0.0; }
    double variance() const { return count > 1 ? m2 / (count - 1) : 0.0; }

private:
    int count = 0;
    double mean = 0.0;
    double m2 = 0.0;
};

int main() {
    StatisticsAccumulator accumulator;
    for (double value : {2.0, 4.0, 4.0, 4.0, 5.0, 5.0, 7.0, 9.0}) {
        accumulator.add(value);
    }
    std::cout << "Mean: " << accumulator.average() << '\n';
    std::cout << "Variance: " << accumulator.variance() << '\n';
}
