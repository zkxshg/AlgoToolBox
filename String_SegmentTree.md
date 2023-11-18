The algorithm in `String_SegmentTree.cpp` implements a Segment Tree data structure. A Segment Tree is a binary tree used for storing information about intervals or segments. It allows for efficient querying and updating of interval-based data.

**Goal of the Algorithm:**
The main goal of the Segment Tree algorithm is to facilitate the efficient execution of range queries and updates. 

**Input:**
The `createSegmentTree` function takes a vector of pairs, which represents a list of intervals.

**Output:**
The `createSegmentTree` function does not return any value. However, the segment tree can be retrieved using the `getSegmentTree` function, which returns a pointer to the array representing the tree.

**Algorithm Steps:**

1. **buildTree:** This function is used to construct the segment tree. It initiates each node in the tree with a value of 0.

2. **update:** This function is used to increment the value of each node in the tree that represents a segment falling within a given range.

3. **query:** This function is used to retrieve the sum of all nodes in the tree that represent a segment falling within a given range.

4. **createSegmentTree:** This function initiates the creation of the segment tree. It first determines the maximum end value among all intervals to establish the size of the tree. It then calls `buildTree` to construct the tree and subsequently uses `update` to populate the tree based on the given intervals.

**Time Complexity:**

- The time complexity of the `buildTree` function is O(n), where n is the size of the array.
- The time complexity of the `update` and `query` functions is O(log n), where n is the size of the array.
- The time complexity of the `createSegmentTree` function is O(n log n), where n is the number of intervals, assuming that the intervals are not overlapping. In the worst-case scenario, where all intervals are overlapping, the time complexity is O(n^2 log n).

**Space Complexity:**
The space complexity of the Segment Tree is O(n), where n is the size of the array.

**Example:** Given the intervals [(2, 5), (1, 3)], calling `createSegmentTree([(2, 5), (1, 3)])` will update the segment tree based on these intervals. Then, calling `query(1, 0, maxEnd, left, right)` will return the sum of all nodes in the tree that represent a segment falling within the range [left, right].
