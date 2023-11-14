The algorithm in `Graph_CloneGraph.cpp` creates a deep copy (clone) of a given graph.

**Goal of Algorithm:**
The algorithm's purpose is to create a deep copy of a given graph. This means that the nodes and edges in the new graph are all newly created instances, rather than references to the nodes and edges in the original graph.

**Input:**
The algorithm takes a pointer to a `Node` as input, which represents the root node of the graph to be cloned.

**Output:**
The algorithm returns a pointer to a `Node`, which is the root node of the cloned graph.

**Algorithm Steps:**
1. If the input node is null, return null.
2. Create a new `Node` `root` with the same value as the input node.
3. If the input node has no neighbors, return `root`.
4. Initialize an `unordered_map` `searchSet` to keep track of the nodes that have been visited, and an `unordered_map` `nodeDict` to store the correspondence between the values of the nodes in the original graph and the nodes in the cloned graph.
5. Initialize two queues `Q1` and `Q2` to perform a breadth-first search (BFS) on the original graph and build the cloned graph simultaneously.
6. Push the input node into `Q1` and `root` into `Q2`.
7. Enter a while loop that continues until `Q1` is empty.
8. In each iteration of the loop, take the front nodes from `Q1` and `Q2`.
9. For each neighbor of the node from `Q1`, check if it has been visited.
10. If it hasn't been visited, create a new `Node` with the same value, mark it as visited, store it in `nodeDict`, add it to the neighbors of the node from `Q2`, and push it and the neighbor into `Q1` and `Q2`, respectively.
11. If it has been visited, add the corresponding node from `nodeDict` to the neighbors of the node from `Q2`.
12. After processing all neighbors, pop the front nodes from `Q1` and `Q2`.
13. Finally, return `root` as the root node of the cloned graph.

**Time complexity: O(V + E)**, where `V` is the number of nodes and `E` is the number of edges in the graph. This is because the algorithm performs a BFS on the graph, visiting each node and edge once.

**Space complexity: O(V)**, because the algorithm maintains a queue and two hash maps that store up to `V` nodes.

This algorithm uses BFS and hash maps to efficiently clone a graph.

For example, given a graph with nodes `1`, `2`, `3`, and `4`, where `1` is connected to `2` and `4`, `2` is connected to `1` and `3`, `3` is connected to `2` and `4`, and `4` is connected to `1` and `3`, the output will be a new graph with the same structure.
