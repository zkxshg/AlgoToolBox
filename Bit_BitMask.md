The algorithm in `Bit_BitMask.cpp` generates all subsequences of a string with a given length using a bit mask.

**Goal of Algorithm:**
The algorithm's purpose is to generate all subsequences of a given string `characters` of a specific length `combinationLength`.

**Input:**
The algorithm takes a string `characters` and an integer `combinationLength` as inputs.

**Output:**
The algorithm returns a vector of strings, which are all the subsequences of `characters` of length `combinationLength`.

**Algorithm Steps:**
1. Calculate the length of the `characters` string and compute `maskLen` as the power of 2 raised to the length of the string. This represents the total number of possible combinations of characters in the string.
2. Initialize an empty vector `result` to store the subsequences.
3. Iterate over all numbers from `0` to `maskLen - 1`. Each number can be viewed as a binary representation (bit mask) where a `1` bit at position `j` indicates the inclusion of the `j`-th character from the string in the subsequence.
4. For each number, initialize a bitset `bits` with the number, and create an empty string `str`.
5. Iterate over all bits in `bits`. If a bit at position `j` is `1`, append the `j`-th character from `characters` to `str`.
6. After constructing `str`, if its length is equal to `combinationLength`, add `str` to the `result` vector.
7. After iterating over all numbers, return the `result` vector.

**Time complexity: O(2^n * n)**, where `n` is the length of the string. The algorithm generates all possible combinations of `n` characters, which amounts to `2^n` combinations. For each combination, it constructs a string which requires `O(n)` time.

**Space complexity: O(2^n * n)**, where `n` is the length of the string. In the worst-case scenario, all `2^n` combinations will be of length `n`, which requires `2^n * n` space.

This algorithm uses the concept of a bit mask to generate all possible combinations of characters in the string, and then it selects only those combinations that have the specified length.

For example, given `characters = "abc"` and `combinationLength = 2`, the output would be `["ab", "ac", "bc"]` because these are all the subsequences of "abc" with length 2.
