// https://en.wikipedia.org/wiki/Maximum_subarray_problem

vector<int> Kanade(vector<int>& profit) {
    int len = profit.size();
    int start = 0, end = 0, tempPro = profit[0];
    int maxStart = 0, maxEnd = 0, maxPro = profit[0];

    for (int i = 1; i < len; i++) {
        if (tempPro + profit[i] > profit[i]) {
            tempPro = tempPro + profit[i];
            end = i;
            if (tempPro > maxPro) {
                maxStart = start;
                maxEnd = end;
                maxPro = tempPro;
            }
        }
        else {
            tempPro = profit[i];
            start = i;
            end = i;
            if (tempPro > maxPro) {
                maxStart = start;
                maxEnd = end;
                maxPro = tempPro;
            }
        }
    }

    vector<int> result;
    result.push_back(maxPro); result.push_back(maxStart); result.push_back(maxEnd);
    return result;
}
