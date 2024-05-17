# Cycle Detection Algorithm

The cycle detection algorithm presented here provides a solution to determine whether a given graph contains cycles. It offers separate implementations for both directed and undirected graphs using a topological sorting approach.

## Goal of Algorithm:
The primary objective of this algorithm is to identify whether a given graph contains cycles. It distinguishes between directed and undirected graphs and employs different strategies accordingly to detect cycles.

## Input:
The functions `hasCycleUndirected` and `hasCycleDirected` accept a 2D vector `edges` representing the edges in the graph. Each entry `edges[i]` contains the neighbors of node `i`. The algorithm analyzes this information to determine the presence of cycles.

## Output:
Both functions return a boolean value:
- `true` indicates that the graph contains cycles.
- `false` indicates that the graph is acyclic.

## Algorithm Steps:

### For Undirected Graphs:
1. Calculate the degree of each node in the graph.
2. Enqueue nodes with degrees less than or equal to 1.
3. While the queue is not empty, dequeue a node and decrement the degree of its neighbors. If any neighbor's degree becomes 1, enqueue it.
4. If there are nodes remaining with degrees greater than 1, the graph contains cycles.

### For Directed Graphs:
1. Calculate the indegree of each node in the graph.
2. Enqueue nodes with an indegree of 0.
3. While the queue is not empty, dequeue a node and decrement the indegree of its neighbors. If any neighbor's indegree becomes 0, enqueue it.
4. If there are nodes remaining with indegrees greater than 0, the graph contains cycles.

## Time Complexity:
The time complexity of both implementations is O(V + E), where V represents the number of vertices and E represents the number of edges in the graph. This complexity arises from the traversal of the graph to calculate degrees or indegrees and the subsequent queue operations.

