#include <vector>
#include <queue>

using namespace std;

bool hasCycleUndirected(const vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> degrees(n, 0);

    // Calculate degrees of each node
    for (const auto& edge : edges) {
        for (int node : edge) {
            degrees[node]++;
        }
    }

    queue<int> q;

    // Enqueue nodes with degree <= 1
    for (int i = 0; i < n; ++i) {
        if (degrees[i] <= 1) {
            q.push(i);
        }
    }

    // Loop to add node whose degree <=1 after pop
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : edges[node]) {
            if (--degrees[neighbor] == 1) {
                q.push(neighbor);
            }
        }
    }

    // If there's any node left with degree > 1, there's a cycle
    for (int degree : degrees) {
        if (degree > 1) {
            return true;
        }
    }

    return false;
}

bool hasCycleDirected(const vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> indegrees(n, 0);

    // Calculate indegrees of each node
    for (const auto& edge : edges) {
        for (int node : edge) {
            indegrees[node]++;
        }
    }

    queue<int> q;

    // Enqueue nodes with indegree = 0
    for (int i = 0; i < n; ++i) {
        if (indegrees[i] == 0) {
            q.push(i);
        }
    }

    // loop to add nodes whose degree = 0
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : edges[node]) {
            if (--indegrees[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If there's any node left with indegree > 0, there's a cycle
    for (int indegree : indegrees) {
        if (indegree > 0) {
            return true;
        }
    }

    return false;
}
