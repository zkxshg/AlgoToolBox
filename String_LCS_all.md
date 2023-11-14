The algorithm in `String_LCS_all.cpp` finds the number of possible paths for the Longest Common Subsequence (LCS) between two given strings.

**Goal of the Algorithm:**
The main goal is to find the number of distinct longest common subsequences between two given strings.

**Input:**
The function `numDistinct` takes as input two strings `s` and `t`.

**Output:**
The function `numDistinct` returns the number of distinct longest common subsequences between `s` and `t`.

**Algorithm Steps:**

1. The function initializes a dynamic programming (DP) table `dp` of size (m+1) x (n+1), where m and n are the sizes of the strings `s` and `t` respectively. Each cell in the table `dp[i][j]` represents the length of the longest common subsequence between the prefixes `s[0..i-1]` and `t[0..j-1]`.

2. It also initializes a `match` array to keep track of the positions in the DP table where a character match occurs, and a map `path` to store the number of paths to a particular cell in the DP table.

3. The function then fills the DP table using standard LCS algorithm. For each character match, it adds the current position to the `match` array for the corresponding length of the LCS.

4. If no LCS of length `n` is found, it returns 0.

5. If an LCS of length `n` is found, the function then traces back from each position in the `match` array of length `n` using the `traceBack` function. The `traceBack` function recursively traces back to all possible previous positions and updates the `path` map for the current position.

6. Finally, the function sums up the number of paths for all positions in the `match` array of length `n` and returns it.

**Time Complexity:**
The time complexity of the algorithm is O(mn), where m and n are the lengths of the input strings.

**Space Complexity:**
The space complexity of the algorithm is O(mn), as it creates a DP table and a `match` array of size m by n, and a map `path` which can potentially store up to m*n entries.

Example: Given two strings `"rabbbit"` and `"rabbit"`, calling `numDistinct("rabbbit", "rabbit")` will return `3`, which is the number of distinct longest common subsequences between "rabbbit" and "rabbit".
