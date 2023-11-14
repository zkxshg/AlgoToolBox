The algorithm in `String_LIS.cpp` computes the length of the Longest Increasing Subsequence (LIS) in a given sequence.

**Goal of the Algorithm:**
The main goal is to find the length of the longest increasing subsequence in a given sequence.

**Input:**
The function `lengthOfLIS` takes as input a vector of integers `nums`.

**Output:**
The function `lengthOfLIS` returns the length of the longest increasing subsequence in `nums`.

**Algorithm Steps:**

1. The function starts by checking if the length of `nums` is less than 2. If it is, the function returns the length of `nums` as the length of the LIS.

2. It then initializes a vector `tri` and adds the first element of `nums` to it.

3. The function then iterates over `nums`. For each number `n` in `nums`, it iterates over `tri` and checks if `n` is less than or equal to the current element in `tri`. If it is, it replaces the current element in `tri` with `n` and breaks the inner loop. If `n` is greater than all elements in `tri`, it adds `n` to `tri`.

4. Finally, it returns the size of `tri` as the length of the LIS.

This algorithm uses the concept of patience sorting, and `tri` can be seen as a stack of piles in patience sorting where the top card of each pile is stored.

**Time Complexity:**
The time complexity of the algorithm is O(n^2), where n is the length of the input sequence. This is because for each element in the sequence, it potentially iterates over all elements in `tri`.

**Space Complexity:**
The space complexity of the algorithm is O(n), where n is the length of the input sequence. This is because in the worst case, the size of `tri` can be equal to the size of `nums`.

Example: Given the input sequence `[10, 9, 2, 5, 3, 7, 101, 18]`, calling `lengthOfLIS(nums)` will return `4`, which is the length of the longest increasing subsequence `[2, 3, 7, 101]`.
