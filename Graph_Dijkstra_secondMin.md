### Dijkstra's Algorithm for Finding Second Minimum Path

The `secondMinimum` function in `Graph_Dijkstra.cpp` implements Dijkstra's algorithm to find both the shortest and second shortest paths from node 1 to node n in a graph.

**Goal of Algorithm**: This algorithm aims to compute the shortest and second shortest paths from the source node (node 1) to a destination node (`n`) in a given graph.

**Input**:
- `n`: An integer representing the number of nodes in the graph.
- `edges`: A 2D vector where each sub-vector `[u, v]` represents a bidirectional edge between nodes `u` and `v`.
- `time` and `change`: Parameters used for adjustments in calculating path lengths.

**Output**:
- An integer representing the length of the second shortest path from node 1 to node n.

**Algorithm Steps**:

1. **Graph Construction**: Construct an adjacency list from the given edge list `edges`.

2. **Dijkstra's Algorithm Initialization**:
   - Initialize two arrays `dist` and `secondDist` with `INT_MAX`, where `dist[i]` stores the shortest distance and `secondDist[i]` stores the second shortest distance from node 1 to node `i`.
   - Use a priority queue (`pq`) to manage nodes and their current shortest distances.

3. **Dijkstra's Algorithm Execution**:
   - Start from node 1 with a distance of 0. Push `{0, 1}` into the priority queue.
   - Process nodes in order of increasing distance:
     - For each node processed (`u`), update its neighboring nodes (`v`):
       - Calculate the new distance through `u` to `v`.
       - Update `dist[v]` and `secondDist[v]` accordingly if shorter paths are found.

4. **Result Calculation**:
   - Retrieve `secondDist[n]`, which represents the second shortest path length from node 1 to node n.
   - Adjust the result based on specific conditions, ensuring it meets problem constraints if necessary.

**Time Complexity**: The time complexity of the algorithm is `O((V + E) log V)`, where `V` is the number of vertices and `E` is the number of edges, due to the use of a priority queue in Dijkstra's algorithm.

**Space Complexity**: The space complexity is `O(V + E)`, primarily due to the adjacency list and priority queue used in Dijkstra's algorithm.

**Example**:
For a graph with 4 nodes and edges represented as `[[1, 2], [2, 3], [3, 4], [1, 3], [2, 4]]`, and assuming `n = 4`, the function will return the length of the second shortest path from node 1 to node 4 based on the calculated `secondDist`.
