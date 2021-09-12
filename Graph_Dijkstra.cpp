struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }    
};


vector<int> Dijkstra(vector<vector<int>>& edges, int n) {
    vector<int> dist(n, INT_MAX); dist[0] = 0;

    unordered_map<int, unordered_map<int, int>> path;
    for (auto& e : edges) path[e[0]][e[1]] =path[e[1]][e[0]] = e[2];

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> nodes;
    nodes.push({0, 0});

    while (!nodes.empty()) {
        int N =  nodes.top().first; nodes.pop();

        for (auto& p : path[N]) {
            int v = p.first, d = p.second;

            if (dist[N] + d < dist[v]) {
                dist[v] = dist[N] + d;
                nodes.push(make_pair(v, dist[v]));
            }
        }
    }

    return dist;
}
