The algorithm in `Sort_QuickSort.cpp` is an implementation of the Quick Sort algorithm, which is a divide-and-conquer sorting algorithm.

**Goal of the Algorithm:**
The main goal is to sort an array of integers in ascending order.

**Input:**
The `sortArray` function takes a vector of integers `nums` as input.

**Output:**
The `sortArray` function returns a vector of sorted integers.

**Algorithm Steps:**

1. The `sortArray` function initiates the Quick Sort process by calling the `QuickSort` function with the input array `nums`.

2. The `QuickSort` function begins by choosing the first element in the range as the pivot.

3. It then partitions the array into two parts: elements less than or equal to the pivot, and elements greater than the pivot.

4. It does this by initializing two pointers, `i` and `j`, at the second element and last element of the range, respectively, and then moves them towards each other. `i` is moved right until an element greater than the pivot is found, and `j` is moved left until an element less than the pivot is found, then these two elements are swapped.

5. When `i` and `j` cross, the partitioning is complete. The pivot is then swapped with `j` to put it in its correct position.

6. The `QuickSort` function is then recursively called on the two partitions.

**Time Complexity:**
The average time complexity of Quick Sort is O(N log N), where N is the size of the array. However, in the worst-case scenario (already sorted array), it can go up to O(N^2).

**Space Complexity:**
The space complexity of Quick Sort is O(log N) due to the recursive stack if the partitioning is balanced. In the worst case, it can be O(N).

Example: If `nums` is `[4, 3, 2, 1]`, calling `sortArray(nums)` will return `[1, 2, 3, 4]`, which is the sorted version of the input array.
