The algorithm implemented in `String_EditDist.cpp` is a dynamic programming algorithm designed to solve the Minimum Edit Distance problem.

**Goal of Algorithm:**
The main goal of the algorithm is to find the minimum number of operations (insertions, deletions, and substitutions) required to transform one string `word1` into another string `word2`.

**Input:**
The function `minDistance` takes two strings `word1` and `word2` as input.

**Output:**
The function returns an integer representing the minimum number of operations required to convert `word1` into `word2`.

**Algorithm Steps:**

1. **Initialization:** The algorithm first initializes a 2D dynamic programming table `dp` of size (m+1) x (n+1), where m is the length of `word1` and n is the length of `word2`. The first row and the first column are filled with negative of their indices, representing the cost of converting a string to an empty string.

2. **Fill DP Table:** The algorithm then iterates through each cell of the `dp` table. For each cell at position (i, j), it considers three scenarios:

    - deleting a character from `word1` (i.e., moving from cell (i-1, j) to cell (i, j) at a cost of 1)
    - inserting a character into `word1` (i.e., moving from cell (i, j-1) to cell (i, j) at a cost of 1)
    - replacing a character in `word1` with a character from `word2` (i.e., moving from cell (i-1, j-1) to cell (i, j) at a cost of 1 if the characters at position i in `word1` and position j in `word2` are different, or at no cost if the characters are the same)

    It then fills the cell at position (i, j) with the maximum value among the three scenarios.

3. **Return Result:** Finally, it returns the negative of the value in the last cell of the `dp` table (i.e., cell at position (m, n)) as the minimum number of operations required to convert `word1` into `word2`.

**Time Complexity:**
The time complexity of the algorithm is O(m*n), where m is the length of `word1` and n is the length of `word2`, as it needs to fill a 2D dynamic programming table of size (m+1) x (n+1).

**Space Complexity:**
The space complexity of the algorithm is also O(m*n), due to the 2D dynamic programming table.

For example, given the input `word1 = "horse"` and `word2 = "ros"`, the `minDistance` function will return `3` as it takes three operations to convert `word1` into `word2`: replace 'h' with 'r', remove 'o', and remove 'e'.
