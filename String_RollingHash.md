The algorithm implemented in `String_RollingHash.cpp` is designed to solve the problem of finding the shortest palindrome by adding characters in front of a given string. It employs the concept of a Rolling Hash, which is a hash function where the input is hashed in a window that moves through the string.

**Goal of Algorithm:**
The primary goal of this algorithm is to find the shortest palindrome by adding characters in front of the input string `s`.

**Input:**
The function `shortestPalindrome` takes a string `s` as input.

**Output:**
The function returns a string that is the shortest palindrome obtained by adding characters in front of `s`.

**Algorithm Steps:**

1. **Edge Case:** If the length of `s` is less than 2, it returns `s` as any string with length less than 2 is a palindrome.

2. **Hash Computation:** The algorithm computes the hash value of `s` and its reverse `revStr`. The hash function multiplies the current hash value by a prime base and adds the current character, followed by taking the modulus with a prime number.

3. **Palindrome Check:** The algorithm checks if `s` is already a palindrome by comparing the hash value of `s` and `revStr`. If they are equal, it returns `s`.

4. **Substring Removal:** The algorithm then enters a loop where it removes one character at a time from the end of `s` and the beginning of `revStr`. It updates the hash values accordingly and checks if the updated substrings are palindromes. The loop continues until it finds a palindrome or all characters are removed.

5. **Palindrome Construction:** The algorithm constructs the shortest palindrome by adding the non-palindromic part at the beginning of `s`.

**Time Complexity:**
The time complexity of the algorithm is O(n), where n is the length of `s`. The algorithm scans `s` once to compute the hash values and then performs constant-time operations for each character.

**Space Complexity:**
The space complexity of the algorithm is O(n), due to the space required for the input and output strings.

For example, given the input `s = "abc"`, the `shortestPalindrome` function will return `"cbabc"` as the shortest palindrome that can be obtained by adding characters in front of `s`.
