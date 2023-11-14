The algorithm in `Sort_MergeSort.cpp` is an implementation of the Merge Sort algorithm, which is a type of divide-and-conquer algorithm used for sorting an array.

**Goal of the Algorithm:**
The main goal of this algorithm is to sort an array of numbers in ascending order.

**Input:**
The `sortArray` function takes a vector of integers `nums` as input.

**Output:**
The `sortArray` function returns a vector of sorted integers.

**Algorithm Steps:**

1. The `sortArray` function calls the `mergeSort` function on the input array `nums`.

2. The `mergeSort` function first checks if the array has more than one element. If not, it returns as an array of a single element is already sorted.

3. It then finds the middle index of the array and recursively calls `mergeSort` on the two halves of the array.

4. A temporary array `temp` is created to store the merged and sorted halves.

5. The function then merges the two sorted halves into `temp` by comparing the smallest unplaced elements in both halves and placing the smaller one next in `temp`. 

6. Finally, the sorted elements from `temp` are copied back into the original array `B`.

**Time Complexity:**
The time complexity of the Merge Sort algorithm is O(N log N) where `N` is the size of the array. This is because the array is divided into two halves in each recursive call and then merged in linear time.

**Space Complexity:**
The space complexity is O(N) as the algorithm uses a temporary array `temp` to store the merged halves of the array.

Example: If `nums` is `[4, 3, 1, 2]`, calling `sortArray(nums)` will return `[1, 2, 3, 4]`, which is the sorted version of the input array.
