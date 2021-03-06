// https://en.wikipedia.org/wiki/Reservoir_sampling

class Solution {
public:
    vector<int> A;

    Solution(vector<int>& nums) {
        A = nums;
    }

    int pick(int target) {
        int n = 1;
        int res = 0;
        int len = A.size();

        for (int i = 0; i < len; i++) {
            if (A[i] == target) {
                int ran = rand() % n;
                if (ran >= n - 1)  res = i;
                n++;
            }
        }

        return res;
    }
};

/**
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
