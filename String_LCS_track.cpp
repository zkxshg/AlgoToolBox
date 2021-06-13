int DP_LCS_Algorithm(int* A, int* B, int m, int n) {
    // 0 Initialize
    int** Benson1 = new int* [m];  
    for (int i = 0; i < m; i++) {
        Benson1[i] = new int[n];
        for (int j = 0; j < n; j++) Benson1[i][j] = 0;
    } 

    // 1 boundary conditions
    for (int i = 0; i < m; i++) {
        if (A[i] == B[0]) Benson1[i][0] = 1;
        else if (i > 0) Benson1[i][0] = Benson1[i - 1][0];
    }
    for (int i = 0; i < n; i++) {
        if (A[0] == B[i]) Benson1[0][i] = 1;
        else if (i > 0)  Benson1[0][i] = Benson1[0][i - 1];
    }
    // 2 Use DP to calculate the LCS(i, j)
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            Benson1[i][j] = max(Benson1[i][j - 1], Benson1[i - 1][j]);
            if (A[i] == B[j]) Benson1[i][j] = max(Benson1[i - 1][j - 1] + 1, Benson1[i][j]); // if (i, j) is a match
        }
    }
    int result = Benson1[m - 1][n - 1];  

    // Backtracking
    vector<int> track(result);
    int pos = result - 1, x = m - 1, y = n - 1;
    while (pos >= 0) {
        if (A[x] == B[y]) {
            track[pos] = A[x]; x--; y--;  pos--;
        }
        else {
            if (Benson1[x - 1][y] >= Benson1[x][y - 1]) x--;
            else y--;
        }
    }

    //for (int i : track) cout << i << ","; cout << endl;

    // 3 clear the memory
    for (int i = 0; i < m; i++) delete[] Benson1[i];
    delete[] Benson1;
    return result;
}