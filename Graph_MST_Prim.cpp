int dist(vector<int> a1, vector<int> a2) {
    return abs(a1[0] - a2[0]) + abs(a1[1] - a2[1]);
}

int minCostConnectPoints(vector<vector<int>>& points) {
    int len = points.size();
    if (len < 2) return 0;
    if (len < 3) return dist(points[0], points[1]);

    int maxVal = 2 * pow(10, 6) + 1;

    // Distance Matrix
    vector<vector<int>> distM(len, vector<int>(len, maxVal));
    for (int i = 0; i < len; i++) {
        for (int j = 1; j < len; j++) {
            if (i != j) distM[i][j] = dist(points[i], points[j]);
        }
    }

    int* minVals = new int[len];
    int* minValsPos = new int[len];
    bool* ifCut = new bool[len];

    for (int i = 0; i < len; i++) {
        minValsPos[i] = 0;
        minVals[i] = distM[0][i];
        ifCut[i] = false;
    }
    ifCut[0] = true;

    int totalDist = 0;

    for (int i = 1; i < len; i++) {

        int minN = -1, minDist = maxVal;
        for (int j = 1; j < len; j++) {
            if (!ifCut[j] && minVals[j] < minDist) {
                minN = j;
                minDist = minVals[j];
            }
        }

        for (int j = 1; j < len; j++) {
            if (j != minN && !ifCut[j] && distM[minN][j] < minVals[j]) minVals[j] = distM[minN][j];
        }

        totalDist += minDist;
        ifCut[minN] = true;
    }

    delete[] minVals;
    delete[] minValsPos;
    delete[] ifCut;
    return totalDist;
}

