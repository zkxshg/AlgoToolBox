#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#define M matrix

void rotate(vector<vector<int>>& matrix) {
    int n = M.size();

    for (int i = 0; i < n / 2; i++) {
        int temp = 0;

        for (int j = i; j < n - i - 1; j++) {
            temp = M[i][j];

            M[i][j] = M[n - j - 1][i];

            M[n - j - 1][i] = M[n - i - 1][n - j - 1];

            M[n - i - 1][n - j - 1] = M[j][n - i - 1];

            M[j][n - i - 1] = temp;
        }
    }
}