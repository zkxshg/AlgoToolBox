int V;

vector<int> par;

int find(int x) {
    return (x == par[x])? x : find(par[x]);
}

void merge(int x, int y) {
    par[find(x)] = find(y);
}

static bool cmp(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

int kruskal(int n, vector<vector<int>>& edges) {
    int E = edges.size();

    par.resize(0); par.resize(n);
    for (int i = 0; i < n; i++) par[i] = i;

    sort(edges.begin(), edges.end(), cmp);

    int cost = 0;
    for (int i = 0, j = 0; i < n - 1 && j < E; i++) {
        // Check circle
        while (j < E && find(edges[j][0]) == find(edges[j][1])) j++;
        if (j >= E) break;

        // add the edge[j]
        merge(edges[j][0], edges[j][1]);
        cost += edges[j][2];

        j++;
    }

    cout << "MST = " << cost << endl;
    return cost;
}
