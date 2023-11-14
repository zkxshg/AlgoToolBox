The algorithm in `List_InsertSortList.cpp` is an implementation of the Insertion Sort algorithm specifically designed for singly linked lists.

**Goal of the Algorithm:**
The main goal of this algorithm is to sort a given singly linked list in ascending order.

**Input:**
The function `insertionSortList` takes a pointer to the head node of a singly linked list.

**Output:**
The function returns the head node of the sorted linked list.

**Algorithm Steps:**

1. Create a new dummy node `pre` as the pre-head of the sorted part of the list.

2. Initialize `temp` to the second node in the list, and `tail` to the first node.

3. Iterate over the list. For each node:
   - If its value is less than the head's value, move it to the front of the list.
   - If its value is greater than or equal to the tail's value, it is already in the correct position, so update `tail` to this node.
   - If its value is in between, find its correct position in the sorted part of the list and insert it there.

4. Return the node next to the dummy node `pre`, which is the head of the sorted list.

**Time Complexity:**
The time complexity of the insertion sort algorithm is O(N^2), where `N` is the number of nodes in the list. This is because in the worst case, every node needs to be compared with every other node.

**Space Complexity:**
The space complexity of the algorithm is O(1), since it sorts the list in place and only uses a constant amount of extra space.

For example, if a linked list has nodes with values `[4, 2, 1, 3]`, the output will be the list with nodes in the order `[1, 2, 3, 4]`, which is the sorted list.
