#!/usr/bin/env python3
from collections import defaultdict, deque

def topological_sort(edges):
    graph = defaultdict(list)
    indegree = defaultdict(int)
    nodes = set()

    for current, nxt in edges:
        graph[current].append(nxt)
        indegree[nxt] += 1
        nodes.add(current)
        nodes.add(nxt)

    queue = deque(sorted(node for node in nodes if indegree[node] == 0))
    order = []

    while queue:
        node = queue.popleft()
        order.append(node)
        for neighbor in graph[node]:
            indegree[neighbor] -= 1
            if indegree[neighbor] == 0:
                queue.append(neighbor)

    if len(order) != len(nodes):
        raise ValueError("Graph contains a cycle")

    return order

if __name__ == "__main__":
    sample_edges = [
        ("fetch", "parse"),
        ("parse", "validate"),
        ("fetch", "cache"),
        ("cache", "respond"),
        ("validate", "respond"),
    ]
    result = topological_sort(sample_edges)
    print("Execution order:", " -> ".join(result))
