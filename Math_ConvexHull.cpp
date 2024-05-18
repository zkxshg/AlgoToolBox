#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return (a.first < b.first) || (a.first == b.first && a.second < b.second);
    }

    static int orientation(const pair<int, int>& p, const pair<int, int>& q, const pair<int, int>& r) {
        int val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);
        if (val == 0) return 0; // collinear
        return (val > 0) ? 1 : 2; // clockwise or counterclockwise
    }

    vector<pair<int, int>> convexHull(vector<pair<int, int>>& points) {
        int n = points.size();
        if (n < 3) return points;

        // Find the point with the lowest y-coordinate (and the leftmost one in case of a tie)
        sort(points.begin(), points.end(), cmp);
        pair<int, int> p0 = points[0];

        // Sort points based on polar angle with respect to p0
        sort(points.begin() + 1, points.end(), [p0](const pair<int, int>& a, const pair<int, int>& b) {
            int o = orientation(p0, a, b);
            if (o == 0) return (dist(p0, a) < dist(p0, b)); // Closer points first if collinear
            return (o == 2); // Counterclockwise sorting
        });

        // Build the convex hull
        vector<pair<int, int>> hull;
        hull.push_back(points[0]);
        hull.push_back(points[1]);
        
        for (int i = 2; i < n; i++) {
            while (hull.size() > 1 && orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) != 2) {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }

        return hull;
    }

    static double dist(const pair<int, int>& p1, const pair<int, int>& p2) {
        int dx = p1.first - p2.first;
        int dy = p1.second - p2.second;
        return dx * dx + dy * dy;
    }
};

int main() {
    Solution sol;
    vector<pair<int, int>> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    vector<pair<int, int>> convexHullPoints = sol.convexHull(points);
    cout << "Convex Hull Points:\n";
    for (const auto& p : convexHullPoints) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }
    return 0;
}

