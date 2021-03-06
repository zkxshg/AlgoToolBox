// Longest Common subsequence in diagonal method

vector<vector<int> > succTable(int* A, int m, int alpha) {
    int len = m;
    vector<vector<int> > succesT(alpha + 1, vector<int>(len + 1, len * 10));
  
    for (int i = len - 1; i >= 0; i--) {
        for (int j = 1; j <= alpha; j++) {
            if (A[i] == j) succesT[j][i] = i + 1; 
            else succesT[j][i] = succesT[j][i + 1];
        }
    }
  
    return succesT;
}


int Diagonal_LCS(int* A, int* B, int m, int n, int alphabet) {
    
    int* d_ij = new int[n]; 
    for (int i = 0; i < n; i++) d_ij[i] = n * 10;

    vector<vector<int> > stB = succTable(B, n, alphabet);

    int maxL = 0;
    for (int i = 0; i < m; i++) {
        int pos = 0;
        for (int j = i; j < m; j++) {
            int nexP = stB[A[j]][pos];

            int minCol = min(d_ij[j - i], nexP);
            if (minCol > n) break;

            d_ij[j - i] = minCol;
            maxL = max(maxL, j - i + 1);
            pos = d_ij[j - i];
        }
        if (m - i < maxL) break;
    }

    delete[] d_ij;
    return maxL;
}
