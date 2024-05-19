The algorithm implemented in `Diagonal_CLCS.cpp` aims to find the length of the Constrained Longest Contiguous Subsequence (CLCS) between two sequences `A` and `B`, given a pattern `P`.

**Goal of Algorithm:**
The primary goal of the algorithm is to determine the length of the longest contiguous subsequence that is common to both sequences `A` and `B`, while also matching a given constrained pattern `P`.

**Input:**
The function `Diagonal_CLCS` takes several inputs:
- Two integer arrays, `A` and `B`, representing the sequences to compare.
- An integer array `P` representing the pattern to match within the common subsequence.
- Integers `m`, `n,` and `r` representing the lengths of arrays `A,` `B,` and `P`, respectively.
- An integer `alpha` indicating the range of characters in the sequences.

**Output:**
The function returns an integer representing the length of the CLCS matching the pattern `P`.

**Algorithm Steps:**

1. **Initialize:** The algorithm initializes a dynamic programming table `d_ijk` to store intermediate results. It sets initial values based on the lengths of sequences and the pattern.

2. **Successor Table:** It computes the successor table `stB` for sequence `B` using the `succTable` function. This table helps optimize the search process.

3. **Diagonal CLCS:** The algorithm performs a diagonal constrained longest common subsequence search between sequences `A` and `B`. It iterates over all possible subsequences of `A` and `B`, updating the dynamic programming table `d_ijk` based on matches and mismatches.

**Time Complexity:**
The time complexity of the algorithm depends on the lengths of sequences `A` and `B`, denoted as `m` and `n` respectively. The worst-case time complexity is O(m * n ).

**Space Complexity:**
The space complexity is O(n * r), where `n` is the length of sequence `B` and `r` is the length of the pattern `P`, due to the dynamic programming table.

For example, given sequences `A = {1, 2, 3, 4, 1, 2, 3, 4, 1}` and `B = {1, 2, 3, 4, 1, 2, 1, 2, 3, 4}`, along with pattern `P = {1, 2, 3, 1, 1}`, the `Diagonal_CLCS` function will return the length of the CLCS matching the pattern, which in this case would be `5`.
