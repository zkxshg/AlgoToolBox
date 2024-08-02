class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges) {
        // Construct adjacency list for the graph
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // Dijkstra's algorithm to find shortest paths from node 1
        vector<int> dist(n + 1, INT_MAX);
        vector<int> secondDist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        dist[1] = 0;
        pq.push({0, 1});
        
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if (d > secondDist[u]) continue;
                
            for (int v : graph[u]) {
                int new_dist = d + 1;
                if (new_dist < dist[v]) {
                    secondDist[v] = dist[v];
                    dist[v] = new_dist;
                    pq.push({new_dist, v});
                } else if (new_dist > dist[v] && new_dist < secondDist[v]) {
                    secondDist[v] = new_dist;
                    pq.push({new_dist, v});
                }
            }
        }

        int minEdgeNum = dist[n], secondMinEdgeNum = secondDist[n];

        if (secondMinEdgeNum >= INT_MAX || secondMinEdgeNum - minEdgeNum > 2) {
            secondMinEdgeNum = minEdgeNum + 2;
        }

        return secondMinEdgeNum;
    }
};
