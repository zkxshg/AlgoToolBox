The algorithm in `String_RabinKarp_one.cpp` implements the Rabin-Karp string-searching algorithm. This is a popular algorithm used for searching a pattern in a text using hashing.

**Goal of the Algorithm:**
The main objective of this algorithm is to find the starting position of the substring `w` in the string `s`.

**Input:**
The function `findSubstringPos` takes as input two strings, `s` and `w`.

**Output:**
The function `findSubstringPos` returns the starting position of the substring `w` in the string `s`. If the substring is not found, it returns -1.

**Algorithm Steps:**

1. The function first calculates the length of the strings `s` and `w`. If `w` is longer than `s` or either of them is empty, it returns -1.

2. It then calculates the hash value of string `w` and the hash value of the first `wlen` characters in string `s` using the `rollingHash` function.

3. The function then iterates through each substring of `s` with length `wlen`. For each substring, it compares its hash value with the hash value of `w`. If the hash values are equal, it further checks if the actual strings are equal. If both are true, it returns the current index `i`, which is the starting position of `w` in `s`.

4. If `w` is not found at the current position, the function updates the hash value of the next substring in `s` by subtracting the effect of the leading character and adding the effect of the next character.

5. If `w` is not found in `s`, the function returns -1.

**Time Complexity:**
The time complexity of the algorithm is O(n + m), where n is the length of the string `s` and m is the length of the string `w`.

**Space Complexity:**
The space complexity of the algorithm is O(1), as it only uses a few variables and does not use any data structure that scales with the input size.

**Example:** Given two strings "hello world" and "world", calling `findSubstringPos("hello world", "world")` will return 6, which is the starting position of the substring "world" in "hello world".
