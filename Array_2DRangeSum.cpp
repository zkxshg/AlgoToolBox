vector<vector<int> > P;

vector<vector<int>> getPsum(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();

    // pre sum
    vector<vector<int> > psum(m, vector<int>(n));

    psum[0][0] = matrix[0][0]; // (0,0)

    for (int i = 1; i < m; i++) psum[i][0] = psum[i - 1][0] + matrix[i][0]; // (i,0)
    for (int i = 1; i < n; i++) psum[0][i] = psum[0][i - 1] + matrix[0][i]; // (0,i)

    // (i,j)
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] + matrix[i][j] - psum[i - 1][j - 1];

    return psum;
}

int subSum(vector<vector<int>>& ps, int x1, int y1, int x2, int y2) {
    int res = ps[x2][y2];
    if (x1 > 0) res -= ps[x1 - 1][y2];
    if (y1 > 0) res -= ps[x2][y1 - 1];
    if (x1 && y1) res += ps[x1 - 1][y1 - 1];
    return  res;
}