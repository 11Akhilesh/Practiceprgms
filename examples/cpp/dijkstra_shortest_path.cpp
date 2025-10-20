#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using Graph = std::unordered_map<int, std::vector<std::pair<int, int>>>;

std::unordered_map<int, int> dijkstra(const Graph &graph, int source) {
    std::unordered_map<int, int> distances;
    for (const auto &entry : graph) {
        distances[entry.first] = INT_MAX;
    }
    distances[source] = 0;

    auto cmp = [](const auto &lhs, const auto &rhs) { return lhs.second > rhs.second; };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> queue(cmp);
    queue.emplace(source, 0);

    while (!queue.empty()) {
        auto [node, dist] = queue.top();
        queue.pop();
        if (dist > distances[node]) {
            continue;
        }
        for (const auto &[neighbor, weight] : graph.at(node)) {
            int next = dist + weight;
            if (next < distances[neighbor]) {
                distances[neighbor] = next;
                queue.emplace(neighbor, next);
            }
        }
    }

    return distances;
}

int main() {
    Graph graph = {
        {0, {{1, 4}, {2, 1}}},
        {1, {{3, 1}}},
        {2, {{1, 2}, {3, 5}}},
        {3, {}}
    };

    auto distances = dijkstra(graph, 0);
    for (const auto &[node, distance] : distances) {
        std::cout << "0 -> " << node << " = " << distance << '\n';
    }
}
