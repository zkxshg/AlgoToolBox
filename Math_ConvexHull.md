The algorithm implemented in `Math_ConvexHull.cpp` is called the Graham scan, which is an algorithm for finding the convex hull of a finite set of points in the plane with time complexity O(n log n).

**Goal of Algorithm:**
The main goal of the algorithm is to find the convex hull, that is the smallest convex polygon that contains all the points of a given set of points in the plane.

**Input:**
The algorithm takes as input a 2D vector of integers, where each inner vector represents a point in the 2D plane.

**Output:**
The algorithm gives as output a 2D vector of integers, which represents the points forming the convex hull.

**Algorithm Steps:**

1. **Find p0:** The algorithm starts by finding the point with the lowest y-coordinate (`p0`). If there are multiple points with the same y-coordinate, it chooses the one with the smallest x-coordinate. This is done by traversing all the points in the input and comparing their coordinates.

2. **Sort points by angle with p0:** The algorithm then calculates the angle made by each point with `p0` and the positive x-axis. It stores this angle, along with the distance from `p0` and the index of the point in a new vector. The new vector is then sorted in non-decreasing order based on the angle and distance.

3. **Stack to scan next points:** A stack is used to keep track of the points in the convex hull. `p0` is initially pushed to the stack. The algorithm then iteratively goes through the sorted list of points. For each point, it checks if moving from the two points at the top of the stack to this point makes a non-left turn. If it does, the top point of the stack is removed. After all points are processed, the points remaining in the stack form the convex hull.

4. **Deal with the boundary points with the same angles:** The algorithm then deals with the boundary points that have the same angles. It ensures that if there are multiple points with the same angle, they are all included in the final result.

**Time Complexity:** O(n log n), where n is the number of points. This is because the algorithm mainly consists of sorting the points, which takes O(n log n) time, and a simple traversal of the points, which takes O(n) time.

**Space Complexity:** O(n), as it needs to store all the points.

For example, given a set of points [(1,1), (2,2), (3,3), (4,4), (5,1), (2,1)], the algorithm will return the points [(1,1), (2,1), (4,4), (5,1)], which form the convex hull.
