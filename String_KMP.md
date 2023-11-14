The algorithm implemented in `String_KMP.cpp` is the Knuth–Morris–Pratt (KMP) string-searching algorithm.

**Goal of Algorithm:**
The main goal of the algorithm is to find the first occurrence of a "needle" string in a "haystack" string.

**Input:**
The function `KMP` takes two strings `haystack` and `needle` as input.

**Output:**
The function returns an integer representing the index of the first occurrence of `needle` in `haystack`. If `needle` does not occur in `haystack`, the function returns `-1`.

**Algorithm Steps:**

1. **Edge Cases:** The algorithm first handles some edge cases. If `needle` is empty, it returns `0`. If the length of `haystack` is less than the length of `needle`, it returns `-1`. If `haystack` and `needle` are of the same length, it checks if they are the same string.

2. **Preprocessing:** The algorithm then preprocesses the `needle` string to create the `Ti` table, which stores the length of the longest proper prefix of the substring `needle[0..i]` that is also a proper suffix of this substring. This table will be used to skip characters when a mismatch happens.

3. **Searching:** The algorithm then scans the `haystack` string from left to right. For each character, if it matches the first character of `needle`, it checks if the following characters match `needle`. If all characters match, it returns the current index. If a mismatch happens, it uses the `Ti` table to skip characters and continue the search.

**Time Complexity:**
The time complexity of the KMP algorithm is O(n + m), where n is the length of `haystack` and m is the length of `needle`. This is because the algorithm scans `haystack` and `needle` once to create the `Ti` table and once to perform the search.

**Space Complexity:**
The space complexity of the algorithm is O(m), due to the `Ti` table created for the `needle` string.

For example, given the input `haystack = "hello"` and `needle = "ll"`, the `KMP` function will return `2` as "ll" starts at index 2 in "hello".
