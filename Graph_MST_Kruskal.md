The algorithm in `Graph_MST_Kruskal.cpp` is an implementation of Kruskal's algorithm, a popular algorithm for finding the Minimum Spanning Tree (MST) of a graph.

**Goal of Algorithm:**
The main goal of this algorithm is to find the MST of a given graph. The MST is a subgraph that connects all vertices using the least total weight for its edges.

**Input:**
The function `kruskal` takes an integer `n` representing the number of nodes in the graph and a 2D vector `edges` representing the edges in the graph with their corresponding weights.

**Output:**
The function prints and returns the minimal cost of constructing the MST.

**Algorithm Steps:**

1. Initialize the `par` vector, which keeps track of the parent node for each node in the graph.

2. Sort the `edges` vector in ascending order by edge weight using the `cmp` function.

3. Initialize `cost` to 0. This variable will keep track of the total cost of the MST.

4. Iterate over each edge in the sorted `edges` list. For each edge, check if the parent nodes of its two endpoint nodes are the same by calling `find` on both endpoints. If they are the same, this indicates that adding this edge would create a cycle, so skip this edge.

5. If the edge does not create a cycle, add it to the MST by calling `merge` on the two endpoint nodes and add its weight to the total `cost`.

**Time Complexity:**
The time complexity of Kruskal's algorithm is O(E log E), where `E` is the number of edges. This is because the algorithm sorts the edges, which takes O(E log E) time, and then iterates over each edge, which takes O(E) time. The union-find operations (i.e., `find` and `merge`) are very efficient and can be considered nearly constant time.

**Space Complexity:**
The space complexity of the algorithm is O(V + E), where `V` is the number of vertices and `E` is the number of edges. This is the space required for the `par` vector and the `edges` vector.

For example, if a graph has 4 nodes with edges represented as `[[0, 1, 1], [1, 2, 2], [2, 3, 3], [3, 0, 4]]` (each sub-array represents an edge between the first two numbers with the third number as the weight), the output will be `6`, indicating that the minimum cost to connect all nodes is 6.
