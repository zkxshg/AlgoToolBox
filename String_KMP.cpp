#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> computeLPS(const string& pattern) {
        int m = pattern.size();
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    int KMP(const string& haystack, const string& needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0) return 0;
        if (n < m) return -1;

        vector<int> lps = computeLPS(needle);

        int i = 0; // Index for haystack
        int j = 0; // Index for needle

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                if (j == m) return i - j; // Match found
            } else {
                if (j != 0) {
                    j = lps[j - 1]; // Move j to previous matching position
                } else {
                    i++; // No match, move to next character in haystack
                }
            }
        }

        return -1; // No match found
    }
};

int main() {
    Solution sol;
    string haystack = "ABABDABACDABABCABAB";
    string needle = "ABABCABAB";
    int matchIndex = sol.KMP(haystack, needle);
    if (matchIndex != -1) {
        cout << "Pattern found at index: " << matchIndex << endl;
    } else {
        cout << "Pattern not found!" << endl;
    }
    return 0;
}
