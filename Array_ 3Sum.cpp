// Combination of elements in nums sum to target

// This algorithm finds all the unique combinations of three numbers in a given array that sum up to the target.
// Function threeSum():  takes an array of integers as input and returns all unique triplets where the sum of three elements equals the target.
// Time Complexity: O(n^2). Space Complexity: O(n).

// xSum() is a helper function that finds all combinations of two numbers in a list that sum to a target value.
void xSum(vector<int>& nums, vector<vector<int>>& sol, vector<int> temp, int target) {
    if (nums.size() >= 2) { 
        // Initialize pointers to the list's start (left) and end (right)
        int left = 0;
        int right = nums.size() - 1;

        // If the sum equals the target
        while (left < right) {
            // Calculate the sum of the numbers at the current left and right pointers
            int sum = nums[left] + nums[right];
            
            if (sum == target) {
                vector<int> temp2 = temp; // Copy the temporary list to a new list
                
                temp2.push_back(nums[left]); // Add the numbers at the left and right pointers to the new list
                temp2.push_back(nums[right]);
                
                sol.push_back(temp2); // Add the new list to the solution list
                
                while (left + 1 < nums.size() && nums[left] == nums[left + 1]) left++; // Increment the left pointer
                while (right > 0 && nums[right] == nums[right - 1]) right--; // Decrement the right pointer
                if (left >= right) break;
                
                // Create a new list that excludes the numbers at the current left and right pointers
                vector<int> temnum(nums.begin() + left + 1, nums.begin() + right);

                // Recursively call this function with the new list, the solution list, the temporary list, and the target sum.
                xSum(temnum, sol, temp, target);
                break;
            }
            else if (sum < target) left++;
            else right--;
        }
    }
}

vector<vector<int>> threeSum(vector<int>& nums, int target) {
    vector<vector<int>> sol;
    if (nums.size() < 3) return sol;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i++) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            vector<int> temp;
            temp.push_back(nums[i]);
            vector<int> temnum(nums.begin() + i + 1, nums.end());
            xSum(temnum, sol, temp, target - nums[i]);
        }
    }

    return sol;
}
