#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> values = {1, 2, 3, 4, 5, 6};
    std::vector<int> transformed;
    transformed.reserve(values.size());

    std::transform(values.begin(), values.end(), std::back_inserter(transformed), [](int value) { return value * value; });

    transformed.erase(std::remove_if(transformed.begin(), transformed.end(), [](int value) { return value % 2 == 0; }), transformed.end());

    int result = std::accumulate(transformed.begin(), transformed.end(), 0, std::plus<>());
    std::cout << "Pipeline result: " << result << '\n';
}
