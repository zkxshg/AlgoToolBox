// Merge set of array bound

// The goal of this algorithm is to merge the overlapping vertical bounds (y-coordinates) of a set of rectangles in a plane. 
// Each rectangle is defined by its lower-left (x1, y1) and upper-right (x2, y2) coordinates.

// Input: The algorithm takes as input a list of rectangles,
// each rectangle is represented as a vector of four integers [x1, y1, x2, y2].
// Output: the total area covered by the rectangles.

// Time complexity: O(n^2). Space complexity: O(n).

int rectangleArea(vector<vector<int>>& rectangles) {
    ll ub = 1e9 + 1;
    
    unordered_map<int, vector<pair<int, int> > > bound;
    
    long long totalArea = 0; // Variable to store the total area

    for (auto& rec : rectangles) {
        int x1 = rec[0], y1 = rec[1], x2 = rec[2], y2 = rec[3];

        for (int i = x1; i < x2; i++) {
            vector<pair<int, int> >& B = bound[i];

            if (B.empty()) {
                B.push_back(make_pair(y1, y2)); continue;
            }

            for (int i = 0; i < B.size(); i++) {
                if (y2 < B[i].first) { 
                    // [y1, y2] -> [L, R]
                    B.insert(B.begin() + i, make_pair(y1, y2));
                    break;
                }
                else if (y1 > B[i].second) {
                    // [L, R] -> [y1, y2]
                    if (i == B.size() - 1) {
                        B.push_back(make_pair(y1, y2));
                        break;
                    }
                }
                else if (y2 <= B[i].second) break; // [L,y1, y2, R]
                else {
                    // [L,y1, R, y2]
                    if (i == B.size() - 1 || y2 < B[i + 1].first) {
                        B[i].second = y2; 
                        break; 
                    }
                    else {
                        B[i + 1].first = B[i].first;
                        B.erase(B.begin() + i);
                        i--;
                    }
                }
            }
        }
    }

    // Iterate over each x-coordinate
    for (auto& [x, bounds] : bound) {
        // For each x-coordinate, calculate the total height of non-overlapping bounds
        for (auto& [y1, y2] : bounds) {
            totalArea += y2 - y1;
        }
    }

    // Return the total area
    // Be careful with overflow, so we take modulo with 10^9 + 7
    return totalArea % (int)(1e9 + 7);
}

// Function to merge rectangle bounds
int rectangleArea(vector<vector<int>>& rectangles) {
    // Define an upper bound
    ll ub = 1e9 + 1;

    // Hash map to store bounds for each x-coordinate
    unordered_map<int, vector<pair<int, int> > > bound;

    // Iterate over each rectangle
    for (auto& rec : rectangles) {
        // Extract the coordinates of the rectangle
        int x1 = rec[0], y1 = rec[1], x2 = rec[2], y2 = rec[3];

        // Iterate over the x-coordinates of the rectangle
        for (int i = x1; i < x2; i++) {
            // Get the bounds for the current x-coordinate
            vector<pair<int, int> >& B = bound[i];

            // If there are no bounds for the current x-coordinate, add the new bound and continue
            if (B.empty()) {
                B.push_back(make_pair(y1, y2)); continue;
            }

            // Iterate over the existing bounds to find the correct place to insert the new bound
            for (int i = 0; i < B.size(); i++) {
                // If the new bound is completely below the current bound, insert it here
                if (y2 < B[i].first) { 
                    B.insert(B.begin() + i, make_pair(y1, y2));
                    break;
                }
                    
                // If the new bound is completely above the current bound, check the next bound
                else if (y1 > B[i].second) {
                    if (i == B.size() - 1) {
                        B.push_back(make_pair(y1, y2));
                        break;
                    }
                }
                    
                // If the new bound is completely inside the current bound, ignore it
                else if (y2 <= B[i].second) break;
                else {
                    // If the new bound overlaps with the current bound, merge them
                    if (i == B.size() - 1 || y2 < B[i + 1].first) {
                        B[i].second = y2; 
                        break; 
                    }
                    // If the new bound also overlaps with the next bound, merge all three
                    else {
                        B[i + 1].first = B[i].first;
                        B.erase(B.begin() + i);
                        i--;
                    }
                }
            }
        }
    }
    
    return 0;
}
    
