The algorithm in `String_LCS_track.cpp` computes the Longest Common Subsequence (LCS) between two given sequences and also tracks the actual subsequence.

**Goal of the Algorithm:**
The main goal is to find the longest common subsequence between two given sequences and also return the subsequence.

**Input:**
The function `DP_LCS_Algorithm` takes as input two integer arrays `A` and `B`, and their lengths `m` and `n` respectively.

**Output:**
The function `DP_LCS_Algorithm` returns the length of the longest common subsequence between `A` and `B`. It also constructs the actual subsequence but doesn't return it.

**Algorithm Steps:**

1. The function initializes a 2D array `Benson1` of size `m` x `n` to store the lengths of the longest common subsequences for different prefixes of `A` and `B`.

2. It sets the boundary conditions in `Benson1` based on whether the first character of one sequence matches with any character of the other sequence.

3. It then fills the rest of `Benson1` using a dynamic programming approach. For each cell, it takes the maximum of the cell above it and the cell to its left. If the corresponding characters in `A` and `B` match, it takes the maximum of its current value and the value of the cell diagonally above and to the left plus one.

4. After filling `Benson1`, it saves the length of the LCS in `result`.

5. The function then backtracks from `Benson1[m-1][n-1]` to construct the LCS. It initializes a vector `track` of size `result` to store the LCS. It checks the cells above, to the left, and diagonally above and to the left to decide the next cell to move to. If the current characters in `A` and `B` match, it adds the character to `track` and moves diagonally up-left. Otherwise, it moves up or left depending on which cell has the larger value.

6. Finally, it deallocates the memory used by `Benson1` and returns `result`.

**Time Complexity:**
The time complexity of the algorithm is O(mn), where m and n are the lengths of the input sequences.

**Space Complexity:**
The space complexity of the algorithm is O(mn), as it creates a 2D array of size m by n.

Example: Given two integer arrays `[1, 2, 3, 4, 5]` and `[2, 3, 5]`, calling `DP_LCS_Algorithm(A, B, 5, 3)` will return `3`, which is the length of the longest common subsequence, and the subsequence tracked will be `[2, 3, 5]`.
