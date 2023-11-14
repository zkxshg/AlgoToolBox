The algorithm in `List_MergeSortList.cpp` is an implementation of the Merge Sort algorithm, which is specifically designed for sorting singly linked lists.

**Goal of the Algorithm:**
The main goal of this algorithm is to sort a given singly linked list in ascending order.

**Input:**
The function `sortList` takes a pointer to the head node of a singly linked list.

**Output:**
The function returns the head node of the sorted linked list.

**Algorithm Steps:**

1. The `sortList` function calls `mergeSort` on the head of the list.

2. The `mergeSort` function recursively divides the list into two halves using the `getMid` function until it reaches single node lists.

3. It then merges these sorted halves back together using the `merge` function, in a way that the merged list is also sorted.

4. The `merge` function takes two sorted linked lists and merges them into one sorted linked list.

**Time Complexity:**
The time complexity of the Merge Sort algorithm is O(N log N), where `N` is the number of nodes in the list. This is because the list is divided in half in each recursive call (`log N` divisions) and each division involves scanning through `N` nodes.

**Space Complexity:**
The space complexity of the algorithm is O(log N), where `N` is the number of nodes in the list. This space is used for the recursive call stack in the `mergeSort` function.

For example, if a linked list has nodes with values `[4, 2, 1, 3]`, the output will be the list with nodes in the order `[1, 2, 3, 4]`, which is the sorted list.
