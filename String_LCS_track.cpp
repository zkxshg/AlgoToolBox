// LCS with backtracking the result

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

string LCS_DP_track_str(const string &A, const string &B) {
    int m = A.size(), n = B.size();
    
    // 1. Initialize and boundary conditions
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // 2. Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    // 3. The length of the LCS
    int index = dp[m][n];
    string lcs(index, ' ');  // Preallocate a string of the correct length

    // 4. Backtracking from dp[m][n] to reconstruct the LCS string
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            lcs[--index] = A[i - 1];  // Place the matching character
            i--; 
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    return lcs;
}
