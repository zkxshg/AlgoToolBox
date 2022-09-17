void print2D(vector<vector<int>>& M) {
  int m = M.size(), n = M[0].size();
  
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << M[i][j]; if (j < n - 1) cout << ",";
    }
    cout << endl;
  }
}
