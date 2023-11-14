The algorithm in `Bit_ListAllSubMask.cpp` generates all submasks of a given bit mask `n`.

**Goal of Algorithm:**
The algorithm's purpose is to generate all submasks of a given bit mask `n`. In the context of bit manipulation, a submask of a mask is formed by changing some of the `1` bits in the mask to `0`.

**Input:**
The algorithm takes an integer `n` as an input, which represents a bit mask.

**Output:**
The algorithm returns a vector of integers, which are all the submasks of `n`.

**Algorithm Steps:**
1. Initialize a vector `subMasks` to store the submasks of `n`.
2. Initialize a variable `subs` with the value of `n`.
3. Enter a while loop that continues until `subs` becomes 0.
4. In each iteration of the loop, add `subs` to `subMasks`.
5. Then, calculate the next submask as `(subs - 1) & n` and assign it to `subs`. This operation essentially turns off the rightmost set bit in `subs`.
6. Repeat the previous steps until `subs` becomes 0.
7. Finally, return the `subMasks` vector.

**Time complexity: O(2^m)**, where `m` is the number of `1` bits in `n`. In the worst case, there could be as many as `2^m` submasks.

**Space complexity: O(2^m)**, where `m` is the number of `1` bits in `n`. In the worst case, the algorithm needs to store `2^m` submasks.

This algorithm uses bitwise operations to generate all possible submasks of a given bitmask. 

For example, given `n = 6` (which is `110` in binary), the output would be `[6, 4, 2, 0]` because `6` (`110` in binary), `4` (`100` in binary), `2` (`010` in binary), and `0` (`000` in binary) are all the submasks of `6`.
