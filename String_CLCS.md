## Algorithm Description: Diagonal Longest Common Subsequence (CLCS)

The algorithm in `Diagonal_CLCS.cpp` is an implementation of a method for finding the longest common subsequence (CLCS) between two integer arrays using a diagonal approach.

### Goal of the Algorithm:
The main goal is to find the length of the longest common subsequence between two given integer arrays.

### Input:
The `Diagonal_CLCS` function takes three integer arrays `A`, `B`, and `P`, their lengths `m`, `n`, and `r` respectively, and an integer `alpha` representing the size of the alphabet.

### Output:
The `Diagonal_CLCS` function returns the length of the longest common subsequence between arrays `A` and `B`.

### Algorithm Steps:

1. **Initialize**: Initialize a matrix `d_ijk` which stores the smallest column index for each diagonal.
2. **Generate Successor Table**: Generate a successor table for array `B` using the `succTable` function. This table is used to quickly find the next position of a given character in `B`.
3. **Iterate Over `A`**: Iterate over each character in array `A`.
4. **Extend Subsequence**: For each character, try to extend the subsequence on each diagonal in `B`.
5. **Update d_ijk**: Update `d_ijk` with the minimum of its current value and the next position of the current character in `B`.
6. **Track Maximum Length**: Keep track of the maximum length of the subsequence found so far.
7. **Termination Condition**: Continue the process until all characters in `A` are processed or the remaining characters in `A` are less than the maximum length of the subsequence found so far.

### Time Complexity:
The time complexity of the algorithm is O(mn), where `m` and `n` are the lengths of the input arrays.

### Space Complexity:
The space complexity of the algorithm is O(mn), as it creates a successor table of size `m` by `n` and a matrix `d_ijk` of size `n` by `r`.

### Example:
Given two arrays `A = [1, 2, 3, 4, 5]` and `B = [1, 3, 5]`, with alphabet size `alpha = 5`, calling `Diagonal_CLCS(A, B, 5, 3, 5)` will return `3`, which is the length of the longest common subsequence ("135").
