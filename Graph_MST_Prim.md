The algorithm in `Graph_MST_Prim.cpp` is an implementation of Prim's algorithm, a popular algorithm for finding the Minimum Spanning Tree (MST) of a graph.

**Goal of Algorithm:**
Prim's algorithm's primary goal is to find the MST of a given graph. The MST is a subgraph that connects all vertices with the least total weight for its edges.

**Input:**
The function `minCostConnectPoints` takes a 2D vector `points` representing the nodes in the graph with their coordinates in a 2D space.

**Output:**
The function returns the minimal cost of constructing the MST.

**Algorithm Steps:**

1. Define a `dist` function to calculate the Manhattan distance between two points in the 2D space.

2. Initialize a 2D `distM` matrix to store the pairwise distances between all points.

3. Initialize arrays `minVals`, `minValsPos`, and `ifCut` to store the minimum distance of each point to the MST, the corresponding position, and whether the point has been added to the MST, respectively.

4. Iteratively find the point with the minimal distance to the MST that has not been cut, add it to the MST, and update the minimum distances of the remaining points to the MST.

**Time Complexity:**
The time complexity of Prim's algorithm in this implementation is O(V^2), where `V` is the number of vertices. This is mainly due to the use of a 2D matrix to store distances and the two nested loops used to traverse this matrix.

**Space Complexity:**
The space complexity of the algorithm is O(V^2), where `V` is the number of vertices. This is the space required for the `distM` matrix and the arrays `minVals`, `minValsPos`, and `ifCut`.

For example, if a graph has points represented as `[[0,0], [2,2], [3,10], [5,2], [7,0]]`, the output will be `20`, indicating that the minimum cost to connect all points is 20.
