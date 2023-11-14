The algorithm implemented in `Math_Sudoku.cpp` is a backtracking algorithm designed to solve the Sudoku problem.

**Goal of Algorithm:**
The main goal of the algorithm is to fill a 9x9 Sudoku grid with digits so that each column, each row, and each of the nine 3x3 sub-grids that compose the grid contains all of the digits from 1 to 9.

**Algorithm Steps:**

The algorithm uses three functions:

1. `whichGrid(int x, int y)` that determines which 3x3 grid a cell belongs to based on its coordinates.
2. `backtrack(int x, int y, vector<vector<char>>& B, unordered_map<int, unordered_map<int, int>>& R, unordered_map<int, unordered_map<int, int>>& C, unordered_map<int, unordered_map<int, int>>& G)` that recursively tries to fill the grid with numbers.
3. `solveSudoku(vector<vector<char>>& board)` that prepares the board and starts the backtracking process.

**Backtrack Function:**

1. If the current cell (`x`, `y`) is beyond the grid, the algorithm returns `true`, which means the grid is fully filled.
2. Then, it calculates the next cell to fill. If the current cell is not the last cell in the row, it moves to the next cell in the same row; otherwise, it moves to the first cell in the next row.
3. If the current cell is not empty (i.e., it contains a digit), it moves to the next cell.
4. If the current cell is empty, it tries to fill it with a number from 1 to 9 that does not exist in the current row, column, or 3x3 grid. If such a number is found, it fills the cell with that number and makes a recursive call to fill the next cell.
5. If the recursive call returns `true`, it means the grid is successfully filled, so it returns `true`. If the recursive call returns `false`, it means that the current number cannot lead to a solution, so it removes the current number from the cell and tries the next number.
6. If no number can be placed in the current cell, it returns `false` to backtrack.

**SolveSudoku Function:**

1. It first initializes three hash maps to keep track of the numbers in each row, each column, and each 3x3 grid.
2. Then, it scans the initial board and updates the hash maps for the initial numbers on the board.
3. Finally, it calls the `backtrack` function to fill the board starting from the cell at (0, 0).

**Time Complexity:** The time complexity is O(9^(n)), where n is the number of empty cells. In the worst-case scenario, we might have to fill each empty cell with a number from 1 to 9 and backtrack.

**Space Complexity:** The space complexity is O(n) to keep the recursion stack, where n is the number of empty cells. Plus, we keep three hash maps for rows, columns, and grids, which also contributes to the space complexity.

For example, given a partially filled Sudoku board, the `solveSudoku` function will fill the board in-place following the rules of Sudoku.
