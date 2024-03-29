// Return number of submatrices sum to  target

// The algorithm's goal is to return the number of submatrices in a given 2D matrix whose elements sum up to a given target value.

// Input: The algorithm takes as input a 2D vector of integers matrix and an integer target.
// Output: The algorithm returns an integer which is the count of submatrices whose sum is equal to the target value.

// Time complexity: O(n^2 * m). Space complexity: O(n * m).
    
int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();

    // pre sum
    vector<vector<int> > psum(m, vector<int>(n));

    for (int i = 0; i < n; i++) psum[0][i] = matrix[0][i]; // (0,i)
    // (i,j)
    for (int i = 1; i < m; i++)
        for (int j = 0; j < n; j++)
            psum[i][j] = psum[i - 1][j] + matrix[i][j];

    // loop
    int res = 0;
    for (int x1 = 0; x1 < m; x1++) {
        for (int x2 = x1; x2 < m; x2++) {

            int rsum = 0;
            unordered_map<int, int> rres; rres[0] = 1;

            for (int y = 0; y < n; y++) {
                rsum += psum[x2][y] - (x1 ? psum[x1 - 1][y] : 0);
                if (rres[rsum - target]) res += rres[rsum - target];
                rres[rsum]++;
            }
        }
    }

    return res;

}
