The algorithm in `Bit_BitComplement.cpp` computes the bitwise complement of an integer.

**Goal of Algorithm:**
The algorithm's purpose is to return the bitwise complement of a given integer `N`. In the bitwise complement, all the `1` bits of `N` are flipped to `0` and all the `0` bits are flipped to `1`.

**Input:**
The algorithm takes an integer `N` as an input.

**Output:**
The algorithm returns an integer which is the bitwise complement of `N`.

**Algorithm Steps:**
1. Check if the input `N` is `0` or `1`. If yes, return `1 - N` as the bitwise complement.
2. Initialize a variable `spos` at `31`, representing the highest possible bit position in an integer.
3. Find the most significant bit (MSB) in `N` that is set to `1`. This is done by checking each bit from the highest bit downward until a set bit is found. The position of the MSB is stored in `spos`.
4. Iterate over each bit from the 0th position to `spos` and flip it using the XOR operation.
5. Return `N` as the result.

**Time complexity: O(1)**. The algorithm only involves a few bitwise operations, which are constant time operations.

**Space complexity: O(1)**. The algorithm uses a fixed amount of space to store the input and temporary variables.

This algorithm uses a bitwise operation to flip the bits of the input number. Bitwise operations are a category of operations that work on the binary representations of integers.

For example, given `N = 5` (which is `101` in binary), the output would be `2` because the bitwise complement of `5` is `010` in binary, which is `2` in decimal.
