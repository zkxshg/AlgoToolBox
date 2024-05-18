#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ====== 创建 Successor Table: O(alpha * n) ======
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

int Diagonal_CLCS(int* A, int* B, int* P, int m, int n, int r, int alpha) {
    // 0 Initialize
    vector<vector<int> > d_ijk(n + 1, vector<int>(r + 1, n * 10));
    d_ijk[0][0] = 0;

    // 1 calcuulate successor table
    vector<vector<int> > stB = succTable(B, n, alpha);

    // 2 Diagonal LCS
    int maxL = 0; // 记录 |CLCS| 结果

    for (int i = 0; i < m; i++) {

        for (int j = i; j < m; j++) {

            int nexP = stB[A[j]][0]; // 记录该列的 search 进度

            for (int c = 0; c <= r; c++) {
                if (d_ijk[j - i][c] > n) break;

                // Search the nextPait
                while (nexP <= d_ijk[j - i][c] && nexP <= n) nexP = stB[A[j]][nexP];
                if (nexP > n) break;

                // Update current D_i,j,c
                d_ijk[j - i + 1][c] = min(d_ijk[j - i + 1][c], nexP);

                if (c < r && A[j] == P[c]) 
                    d_ijk[j - i + 1][c + 1] = min(d_ijk[j - i + 1][c + 1], nexP);
            }
            
            if (d_ijk[j - i + 1][0] > n) break;

            if (d_ijk[j - i + 1][r] <= n) maxL = max(maxL, j - i + 1);
        }

        if (m - i < maxL) break;
    }

    /*for (vector<int> v : d_ijk) {
            for (int i : v) cout << i << ","; cout << endl;
        } cout << endl;*/

    return maxL;
}

int main() {
    int A[] = {1, 2, 3, 4, 1, 2, 3, 4, 1};
    int B[] = {1, 2, 3, 4, 1, 2, 1, 2, 3, 4};
    int P[] = {1, 2, 3, 1, 1};
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);
    int r = sizeof(P) / sizeof(P[0]);
    int alpha = 4; // 假设模式串中的字符取值范围为 [1, 4]

    int clcsLength = Diagonal_CLCS(A, B, P, m, n, r, alpha);

    cout << "CLCS Length: " << clcsLength << endl;

    return 0;
}

