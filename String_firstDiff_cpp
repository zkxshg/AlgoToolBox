vector<vector<int>> diffs;

int diff(string& s, int x, int y) {
    int n = s.size();

    if (y >= n) return n;

    if (diffs[x][y] >= 0) return diffs[x][y];

    if (s[x] != s[y]) return y;

    return diff(s, x + 1, y + 1);
}

vector<vector<int>> firstDiff(string num) {
    int n = num.size();

    diffs.resize(n, vector<int>(n, -1));

    for (int i = n - 1; i >= 0; i--) 
        for (int j = i; j < n; j++) 
            diffs[i][j] = diff(num, i, j);
            
    return diffs;
}
