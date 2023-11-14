The algorithm in `Array_SlidingWindowMax.cpp` finds the maximum number in each subarray of size `k` in a given array.

**Goal of Algorithm:**
The aim of this algorithm is to find the maximum value in each subarray of size `k` for a given array. This is often referred to as a "sliding window maximum" problem.

**Input:**
The algorithm takes as input a vector of integers `nums` and an integer `k`, which represents the size of the sliding window.

**Output:**
The algorithm returns a vector of integers, where the `i`-th integer is the maximum value in the `i`-th subarray of size `k` in `nums`.

**Algorithm Steps:**
1. The algorithm first checks for edge cases where the size of the array is 1 or the sliding window size is 1. In these cases, the original array is returned as the result.
2. It then initializes three vectors: `result` to store the final result, `left` to store the maximum value in each block of `k` from left to right, and `right` to store the maximum value in each block of `k` from right to left.
3. The algorithm then iterates over the array in blocks of size `k`. For each block, it calculates the maximum value from the right and the left, storing these maxima in `right` and `left` respectively.
4. Finally, it iterates over the array again, pushing the maximum of `right[i]` and `left[i + k - 1]` to `result` for each `i` from 0 to `len - k + 1`.
5. The algorithm then returns `result`.

**Time complexity: O(n).** The algorithm iterates over the array a constant number of times, where `n` is the number of elements in the array.

**Space complexity: O(n).** The algorithm uses additional space to store the `result`, `left`, and `right` arrays, each of which are of size `n`.

Here's an example to illustrate how the algorithm works. Given the input array `nums = [1,3,-1,-3,5,3,6,7]` and `k = 3`, the output would be `[3,3,5,5,6,7]` because the maximum values in the sliding windows of size 3 are as follows:

```
[1  3 -1] -3  5  3  6  7 -> 3
 1 [3 -1 -3] 5  3  6  7 -> 3
 1  3 [-1 -3  5] 3  6  7 -> 5
 1  3 -1 [-3  5  3] 6  7 -> 5
 1  3 -1 -3 [5  3  6] 7 -> 6
 1  3 -1 -3  5 [3  6  7] -> 7
```
