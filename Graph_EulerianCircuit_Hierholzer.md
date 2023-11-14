The algorithm in `Graph_EulerianCircuit_Hierholzer.cpp` finds an itinerary from a list of tickets using Hierholzer's algorithm for finding an Eulerian path or circuit in a graph.

**Goal of Algorithm:**
The algorithm's purpose is to find a valid itinerary from a list of flight tickets. Each ticket represents a directed edge from an origin to a destination. The itinerary should cover all tickets exactly once and start from a certain airport. The itinerary is represented as a list of airport codes.

**Input:**
The algorithm takes a 2D vector `tickets` as input. Each subvector represents a flight ticket where index 0 is the origin airport and index 1 is the destination airport.

**Output:**
The algorithm returns a vector of strings representing the itinerary.

**Algorithm Steps:**
1. Initialize several data structures: `path` for storing the adjacency list of each airport, `inDeg` and `outDeg` for storing the in-degrees and out-degrees of each airport, `nodes` for storing all airports, and `res` for storing the result itinerary.
2. Construct the adjacency list for each airport and calculate the in-degrees and out-degrees.
3. Sort the neighbors of each airport in descending order to ensure the smallest lexicographic order in the result.
4. Find the start point for the Eulerian path. If the graph has an Eulerian circuit, select any airport as the start point. If the graph has a semi-Eulerian circuit, select the airport with `outDeg > inDeg` as the start point.
5. Perform a depth-first search (DFS) from the start point to find the Eulerian path or circuit. During the DFS, if the current airport has unvisited neighbors, continue the DFS from this airport. Otherwise, add this airport to the result.
6. Reverse the result itinerary and return it.

**Time complexity: O(E log E)**, where `E` is the number of edges (tickets). This is because the algorithm sorts the neighbors of each airport, and Hierholzer's algorithm visits each edge once.

**Space complexity: O(E)**, due to the storage of all edges in the `path`, `inDeg`, `outDeg`, and `res` data structures.

This algorithm uses Hierholzer's algorithm to efficiently find an itinerary that covers all tickets exactly once.

For example, given `tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]`, the output would be `["JFK","MUC","LHR","SFO","SJC"]`. This is because the itinerary starts from "JFK", then travels to "MUC", "LHR", "SFO", and finally "SJC", covering all tickets exactly once.
