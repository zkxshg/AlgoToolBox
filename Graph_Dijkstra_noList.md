The algorithm in `Graph_Dijkstra_noList.cpp` calculates the shortest path from a source node to a destination node within a limited number of steps (K moves) using a variant of Dijkstra's algorithm.

**Goal of Algorithm:**
The algorithm's purpose is to find the shortest path from a source node `src` to a destination node `dst` within `K` moves in a graph. If no such path exists, it returns `-1`.

**Input:**
The algorithm takes in five inputs:
- `n`: The number of nodes in the graph.
- `flights`: A 2D vector where each subvector represents a flight from the node at index 0 to the node at index 1 with a cost of index 2.
- `src`: The source node.
- `dst`: The destination node.
- `K`: The maximum number of moves allowed.

**Output:**
The algorithm returns an integer which is the minimum cost to travel from `src` to `dst` within `K` moves. If no such path exists, it returns `-1`.

**Algorithm Steps:**
1. If the source and destination nodes are the same, return 0. If there are no flights, return `-1`.
2. Initialize a 2D vector `path` to hold the shortest paths from each node to every other node. Initially, set all paths to a large value.
3. Update the `path` vector with the costs of the flights.
4. While `K` is greater than 0, update the shortest paths from `src` to all other nodes using the current shortest paths. This is done by iterating over all nodes and finding the minimum path from `src` to that node either directly or via another node.
5. After updating the paths `K` times, the shortest path from `src` to `dst` is the minimum cost to travel from `src` to `dst` within `K` moves.
6. If this cost is greater than `(K + 1) * 10000`, return `-1` as no such path exists. Otherwise, return the cost.

**Time complexity: O(K * n^2)**, where `n` is the number of nodes and `K` is the maximum number of moves. This is because the algorithm performs `K` iterations of updating the shortest paths between all pairs of nodes.

**Space complexity: O(n^2)**, due to the `path` vector that stores the shortest paths between all pairs of nodes.

This algorithm uses Dijkstra's algorithm to efficiently find the shortest path within a limited number of moves.

For example, given `n = 3`, `flights = [[0,1,100],[1,2,100],[0,2,500]]`, `src = 0`, `dst = 2`, and `K = 1`, the output would be `200`. This is because the shortest path from `0` to `2` within `1` move is `0 -> 1 -> 2` with a cost of `200`.
