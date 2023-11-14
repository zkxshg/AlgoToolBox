The algorithm in `String_LCP.cpp` is an implementation of the Longest Common Prefix (LCP) algorithm using suffix arrays and the Kasai algorithm.

**Goal of the Algorithm:**
The main goal is to find the longest repeated substring in a given string.

**Input:**
The `longestDupSubstring` function takes a string `S` as input.

**Output:**
The `longestDupSubstring` function returns the longest duplicated substring in the input string `S`. If no such substring exists, it returns an empty string.

**Algorithm Steps:**

1. The function `longestDupSubstring` calls `buildSuffixArray` to construct a suffix array for the given string. A suffix array is a sorted array of all suffixes of a given string.

2. The `buildSuffixArray` function initializes a list of suffixes with their indexes and corresponding ranks. The ranks are based on the characters in the string. The suffixes are then sorted using the `cmp` function.

3. The array is iteratively sorted based on the first `2^i` characters. The ranks are updated after each sorting.

4. The `kasai` function is then used to build the LCP array from the suffix array. The LCP array stores the length of the longest common prefix between the consecutive lexicographically sorted suffixes.

5. The `longestDupSubstring` function then finds the maximum length in the LCP array and returns the corresponding substring from the input string.

**Time Complexity:**
The time complexity of building a suffix array is O(n log n), where n is the size of the input string. This is because we sort the suffixes based on their ranks. The `kasai` algorithm has a time complexity of O(n).

**Space Complexity:**
The space complexity of this algorithm is O(n), as it creates a suffix array, inverse suffix array, and LCP array, each of size n.

Example: In the `main` function, if `str` is `"banana"`, calling `longestDupSubstring(str)` will return `"ana"`, which is the longest repeated substring in the word "banana".
