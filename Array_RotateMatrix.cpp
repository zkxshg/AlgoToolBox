// Rotate matrix by 90 degrees (clockwise)

// This algorithm is to rotate a given square matrix 90 degrees clockwise direction. 
// The rotation is done in-place, meaning it doesn't create a new matrix to store the rotated matrix, 
// but instead modifies the original matrix.

// Input: The algorithm takes as input a 2D square matrix matrix.
// Output: It modifies the input matrix itself to be the rotated version.

// Time complexity: O(n^2). Space complexity: O(1).

#define M matrix

void rotate(vector<vector<int>>& matrix) {
    int n = M.size();

    for (int i = 0; i < n / 2; i++) {
        int temp = 0;

        for (int j = i; j < n - i - 1; j++) {
            temp = M[i][j];

            M[i][j] = M[n - j - 1][i];

            M[n - j - 1][i] = M[n - i - 1][n - j - 1];

            M[n - i - 1][n - j - 1] = M[j][n - i - 1];

            M[j][n - i - 1] = temp;
        }
    }
}
