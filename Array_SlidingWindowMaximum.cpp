// Given a size k of a sliding window, return the max sliding window.

// This algorithm is to find the maximum value in each subarray of size k for a given array. 
// This is often referred to as a "sliding window maximum" problem.

// Input: a vector of integers nums and an integer k, which represents the size of the sliding window.
// Output: a vector of integers, where the i-th integer is the maximum value in the i-th subarray of size k in nums.

// Time complexity: O(n). Space complexity: O(n). 

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int len = nums.size(); if (len == 1 || k == 1) return nums;

    vector<int> result;
    vector<int> left(len);
    vector<int> right(len);

    for (int i = 0; i < len; i += k) {
        if (i + k > len) {
            int maxA = INT_MIN;
            for (int j = len - 1; j >= i; j--) {
                maxA = max(maxA, nums[j]);
                right[j] = maxA;
            }

            int maxB = INT_MIN;
            for (int j = i; j < len; j++) {
                maxB = max(maxB, nums[j]);
                left[j] = maxB;
            }
            break;
        }

        int maxA = INT_MIN;
        for (int j = i + k - 1; j >= i; j--) {
            maxA = max(maxA, nums[j]);
            right[j] = maxA;
        }

        int maxB = INT_MIN;
        for (int j = i; j < i + k; j++) {
            maxB = max(maxB, nums[j]);
            left[j] = maxB;
        }
    }

    for (int i = 0; i < len - k + 1; i++) result.push_back(max(right[i], left[i + k - 1]));

    return result;
}

// Function to find the maximum element in each subarray of size k
vector<int> maxSlidingWindow_Comm(vector<int>& nums, int k) {
    // Calculate the length of the input array
    int len = nums.size(); 

    // Handle edge cases where the length of the array or the window size is 1
    if (len == 1 || k == 1) return nums;

    // Initialize the result array and the left and right arrays
    vector<int> result;
    vector<int> left(len);
    vector<int> right(len);

    // Iterate over the array by chunks of size k
    for (int i = 0; i < len; i += k) {
        // Check if the remaining elements are less than k
        if (i + k > len) {
            int maxA = INT_MIN;
            // Find the maximum value from the right for the remaining elements
            for (int j = len - 1; j >= i; j--) {
                maxA = max(maxA, nums[j]);
                right[j] = maxA;
            }

            int maxB = INT_MIN;
            // Find the maximum value from the left for the remaining elements
            for (int j = i; j < len; j++) {
                maxB = max(maxB, nums[j]);
                left[j] = maxB;
            }
            break;
        }

        int maxA = INT_MIN;
        // Find the maximum value from the right for the current window
        for (int j = i + k - 1; j >= i; j--) {
            maxA = max(maxA, nums[j]);
            right[j] = maxA;
        }

        int maxB = INT_MIN;
        // Find the maximum value from the left for the current window
        for (int j = i; j < i + k; j++) {
            maxB = max(maxB, nums[j]);
            left[j] = maxB;
        }
    }

    // Iterate over the array to find the maximum value in each window
    for (int i = 0; i < len - k + 1; i++) result.push_back(max(right[i], left[i + k - 1]));

    // Return the result array
    return result;
}
