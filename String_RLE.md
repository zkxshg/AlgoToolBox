The algorithm implemented in `String_RLE.cpp` is the Run-Length Encoding (RLE) algorithm, which is a simple form of data compression.

**Goal of Algorithm:**
The main goal of this algorithm is to compress the provided string (represented as a vector of characters) by replacing consecutive repeating characters with the character followed by the count of repetition.

**Input:**
The function `compress` takes a vector of characters `chars` as input.

**Output:**
The function modifies the input vector in-place to store the compressed string and returns the length of the compressed string.

**Algorithm Steps:**

1. **Edge Case:** If the length of `chars` is less than 2, it returns the length.

2. **Compression:** The algorithm then scans `chars` from left to right. For each character, it counts the number of consecutive repetitions. If the character is different from the next character or it is the last character, it writes the character and the count (if greater than 1) to `chars`. If the count is greater than 9, it writes each digit separately. 

**Time Complexity:**
The time complexity of the algorithm is O(n), where n is the length of `chars`. This is because the algorithm scans `chars` once.

**Space Complexity:**
The space complexity of the algorithm is O(1), excluding the input and output. Although the algorithm uses a vector `nums` to store the digits of the count, the size of `nums` is limited by the maximum value of the count, which does not depend on the size of the input.

For example, given the input `chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'}`, the `compress` function will modify `chars` to `{'a', '2', 'b', '2', 'c', '3'}` and return `6` as the length of the compressed string.
