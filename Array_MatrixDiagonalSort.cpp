// Sort diagonals of matrix
// https://assets.leetcode.com/uploads/2020/01/21/1482_example_1_2.png

// The purpose of this algorithm is to sort the diagonals in a 2D matrix. 
// Each diagonal in the matrix is sorted in ascending order while keeping the rest of the data structure intact.

// Input: The algorithm takes as input a 2D matrix mat of size m x n.
// Output: The output of the algorithm is the input matrix, but with each of the diagonals sorted in ascending order.

// Time complexity: O((m+n) * min(m,n) * log(min(m,n))). Space complexity: O(m+n).

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    if (m == 1 || n == 1) return mat;

    vector<vector<int>> di(m + n - 1);

    int st = n - 1;
    for (int i = 0; i < m + n - 1; i++) {
        if (st >= 0) {
            int x = 0;
            while (x < m && x + st < n) {
                di[i].push_back(mat[x][x + st]); x++;
            }
        }
        else {
            int nst = -st, y = 0;
            while (y < n && y + nst < m) {
                di[i].push_back(mat[y + nst][y]); y++;
            }
        }
        sort(di[i].begin(), di[i].end());
        st--;
    }

    st = n - 1;
    for (int i = 0; i < m + n - 1; i++) {
        if (st >= 0) {
            int x = 0;
            while (x < m && x + st < n) {
                mat[x][x + st] = di[i][x]; x++;
            }
        }
        else {
            int nst = -st, y = 0;
            while (y < n && y + nst < m) {
                mat[y + nst][y] = di[i][y]; y++;
            }
        }
        st--;
    }

    return mat;
}

// Function to sort the diagonals of a matrix
vector<vector<int>> diagonalSort_Comm(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    
    // If the matrix is a 1D array, return it
    if (m == 1 || n == 1) return mat;

    // Create a 2D vector to store the diagonals of the matrix
    vector<vector<int>> di(m + n - 1);

    // Iterate over each diagonal
    int st = n - 1; // starting column index for the diagonal
    
    for (int i = 0; i < m + n - 1; i++) {
        // If the starting column index is non-negative, we are in the upper half of the matrix
        if (st >= 0) {
            int x = 0; // row index
            // Extract the diagonal from the matrix
            while (x < m && x + st < n) {
                di[i].push_back(mat[x][x + st]); 
                x++;
            }
        }
        // If the starting column index is negative, we are in the lower half of the matrix
        else {
            int nst = -st; // starting row index for the diagonal
            int y = 0; // column index
            // Extract the diagonal from the matrix
            while (y < n && y + nst < m) {
                di[i].push_back(mat[y + nst][y]); 
                y++;
            }
        }
        // Sort the diagonal
        sort(di[i].begin(), di[i].end());
        // Decrement the starting column index for the next diagonal
        st--;
    }

    // Insert the sorted diagonals back into the matrix
    st = n - 1; // reset starting column index for the diagonal
    for (int i = 0; i < m + n - 1; i++) {
        // If the starting column index is non-negative, we are in the upper half of the matrix
        if (st >= 0) {
            int x = 0; // row index
            // Insert the diagonal into the matrix
            while (x < m && x + st < n) {
                mat[x][x + st] = di[i][x]; 
                x++;
            }
        }
        // If the starting column index is negative, we are in the lower half of the matrix
        else {
            int nst = -st; // starting row index for the diagonal
            int y = 0; // column index
            // Insert the diagonal into the matrix
            while (y < n && y + nst < m) {
                mat[y + nst][y] = di[i][y]; 
                y++;
            }
        }
        // Decrement the starting column index for the next diagonal
        st--;
    }

    // Return the matrix with sorted diagonals
    return mat;
}
