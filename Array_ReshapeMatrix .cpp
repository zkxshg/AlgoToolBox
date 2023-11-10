// Reshape an m x n matrix into a new one with a different size r x c keeping its original data.

// The goal of this algorithm is to reshape an m x n matrix into a different r x c size matrix,
// while preserving the original data.

// Input: The algorithm takes as input a 2D matrix mat and two integers r and c,
// which represent the number of rows and columns of the new reshaped matrix respectively.

// Output: The output of the algorithm is a reshaped 2D matrix of size r x c. 
// If the reshaping isn't possible, the original matrix is returned.

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int m = mat.size(), n = mat[0].size(); if (m * n != r * c) return mat;
    
    vector<vector<int> > R(r, vector<int>(c));
    int pos = 0;
    while (pos < m * n) {
        R[pos / c][pos % c] = mat[pos / n][pos % n]; pos++;
    }
    return R;
}
