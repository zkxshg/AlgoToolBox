The algorithm in `Array_RotateMatrix.cpp` rotates a square matrix 90 degrees clockwise in-place. 

**Goal of Algorithm:**
The aim of this algorithm is to rotate a given square matrix 90 degrees clockwise direction. The rotation is done in-place, meaning it doesn't create a new matrix to store the rotated matrix, but instead modifies the original matrix.

**Input:**
The algorithm takes as input a 2D square matrix `matrix`.

**Output:**
The algorithm does not return a value. It modifies the input matrix itself to be the rotated version.

**Algorithm Steps:**
1. The algorithm first calculates the size `n` of the input matrix.
2. It then iterates over the first half of the rows in the matrix. For each row `i`, it performs the following operations:
    - It iterates over the columns from `i` to `n - i - 1`. For each column `j`, it performs a series of swaps to rotate the four elements at positions `(i, j)`, `(j, n - i - 1)`, `(n - i - 1, n - j - 1)`, and `(n - j - 1, i)` 90 degrees clockwise. It uses a temporary variable `temp` to help with the swaps.
3. After the for-loops complete, the input matrix has been rotated 90 degrees clockwise.

**Time complexity: O(n^2).** The algorithm iterates over each element of the matrix once, where `n` is the number of rows (or columns) of the matrix.

**Space complexity: O(1).** The algorithm performs the rotation in-place and uses a constant amount of space to store the size of the matrix and the temporary variable for the swaps. Therefore, the space complexity is constant.

Here's an example to illustrate how the algorithm works. Given the input matrix:

```
1 2 3
4 5 6
7 8 9
```

The matrix after rotation would be:

```
7 4 1
8 5 2
9 6 3
```
