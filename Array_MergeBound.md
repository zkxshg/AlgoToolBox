**Goal of Algorithm:**
The goal of this algorithm is to merge the overlapping vertical bounds (y-coordinates) of a set of rectangles in a plane. Each rectangle is defined by its lower-left (x1, y1) and upper-right (x2, y2) coordinates.

**Input:**
The algorithm takes as input a list of rectangles. Each rectangle is represented as a vector of four integers [x1, y1, x2, y2].

**Output:**
As it stands, the algorithm does not return any output.

**Time complexity: O(n^2).** The algorithm iterates over each rectangle and for each rectangle, it may iterate over the existing bounds to find the correct place to insert the new bound or to merge the existing bounds. Here, n is the total number of rectangles.

**Space complexity: O(n).** The algorithm uses a hash map to store the bounds for each x-coordinate in the plane. In the worst case, each x-coordinate will have a separate bound, so the space complexity is proportional to the number of rectangles.
