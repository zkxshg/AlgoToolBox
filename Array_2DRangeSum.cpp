// Return sum of submatrix [x1,y1]->[x2,y2] in O(1)

// subSum(): function uses the prefix sum matrix to efficiently calculate the sum of any submatrix within the original matrix,
// the submatrix is defined by its top-left and bottom-right corners (x1, y1) and (x2, y2). 
// The function returns this sum.


// Prepare the prefix sum matrix
vector<vector<int> > P;


// getPsum function constructs a prefix sum matrix from the input matrix
vector<vector<int>> getPsum(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();

    // Initialize the prefix sum matrix with the same dimensions as the input matrix
    vector<vector<int> > psum(m, vector<int>(n));

    psum[0][0] = matrix[0][0]; // Fill the first cell

    // Calculate the prefix sum for the first column
    for (int i = 1; i < m; i++) psum[i][0] = psum[i - 1][0] + matrix[i][0];
    // Calculate the prefix sum for the first row
    for (int i = 1; i < n; i++) psum[0][i] = psum[0][i - 1] + matrix[0][i];

    // Calculate the prefix sum for the rest of the matrix
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            
            // Value at each cell is the sum of the cell above it, the cell to the left of it, 
            // the current cell in the original matrix, minus the cell diagonally above and to the left.
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] + matrix[i][j] - psum[i - 1][j - 1];

    // Return the prefix sum matrix
    return psum;
}

// subSum function returns the sum of the submatrix bounded by (x1, y1) and (x2, y2) in the original matrix
int subSum(vector<vector<int>>& ps, int x1, int y1, int x2, int y2) {
    // Start with the pre-calculated sum up to (x2, y2)
    int res = ps[x2][y2];

    // If the submatrix doesn't start at the first row, subtract the sum up to (x1 - 1, y2)
    if (x1 > 0) res -= ps[x1 - 1][y2];
    // If the submatrix doesn't start at the first column, subtract the sum up to (x2, y1 - 1)
    if (y1 > 0) res -= ps[x2][y1 - 1];
    // If the submatrix doesn't start at (0, 0), add back the sum up to (x1 - 1, y1 - 1) as it was subtracted twice
    if (x1 > 0 && y1 > 0) res += ps[x1 - 1][y1 - 1];

    // Return the sum of the submatrix
    return res;
}

vector<vector<int>> getPsum_raw(vector<vector<int>>& matrix) {
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

int subSum_raw(vector<vector<int>>& ps, int x1, int y1, int x2, int y2) {
    int res = ps[x2][y2];
    if (x1 > 0) res -= ps[x1 - 1][y2];
    if (y1 > 0) res -= ps[x2][y1 - 1];
    if (x1 && y1) res += ps[x1 - 1][y1 - 1];
    return  res;
}
