**Goal of Algorithm:**
The purpose of this algorithm is to sort the diagonals in a 2D matrix. Each diagonal in the matrix is sorted in ascending order while keeping the rest of the data structure intact.

**Input:**
The algorithm takes as input a 2D matrix `mat` of size `m x n`.

**Output:**
The output of the algorithm is the input matrix, but with each of the diagonals sorted in ascending order.

**Time complexity: O((m+n) * min(m,n) * log(min(m,n))).** For each of the (m+n-1) diagonals in the matrix, the algorithm sorts the elements. The sorting step has a complexity of `O(min(m,n) * log(min(m,n)))` (considering that a diagonal can't be larger than min(m,n)), and we do this for (m+n-1) diagonals.

**Space complexity: O(m+n).** The algorithm creates a temporary data structure `di` of size (m+n-1) to store the diagonals of the matrix. Therefore, the space complexity is linear in the size of the matrix.
