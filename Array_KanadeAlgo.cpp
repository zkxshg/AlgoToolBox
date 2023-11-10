// Maximum subarray problem
// https://en.wikipedia.org/wiki/Maximum_subarray_problem

// Kadane's Algorithm is designed to solve the Maximum Subarray Problem,
// which is the task of finding the contiguous subarray within a one-dimensional array of numbers that has the largest sum.

// Input: The input to the algorithm is a one-dimensional array of numbers, 
// the array can contain both positive and negative numbers.

// Output: The output of the algorithm is the maximum sum of any contiguous subarray in the input array, 
// also returns the starting and ending indices of the maximum subarray.

// Time complexity: O(n). Space complexity: O(1).
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


// Function implementing Kadane's algorithm to solve the Maximum Subarray Problem
vector<int> Kanade_Comm(vector<int>& profit) {
    // Variables to keep track of the current subarray and the maximum subarray
    int len = profit.size();
    int start = 0, end = 0, tempPro = profit[0]; // current subarray
    int maxStart = 0, maxEnd = 0, maxPro = profit[0]; // maximum subarray

    // Loop through the array
    for (int i = 1; i < len; i++) {
        // Check if the current element should be added to the existing subarray or start a new one
        if (tempPro + profit[i] > profit[i]) {
            // Extend the current subarray
            tempPro = tempPro + profit[i];
            end = i;

            // Check if the current subarray has a larger sum than the maximum found so far
            if (tempPro > maxPro) {
                // Update maximum subarray details
                maxStart = start;
                maxEnd = end;
                maxPro = tempPro;
            }
        } else {
            // Start a new subarray
            tempPro = profit[i];
            start = i;
            end = i;

            // Check if the new subarray has a larger sum than the maximum found so far
            if (tempPro > maxPro) {
                // Update maximum subarray details
                maxStart = start;
                maxEnd = end;
                maxPro = tempPro;
            }
        }
    }

    // Prepare the result
    vector<int> result;
    result.push_back(maxPro);   // Maximum sum
    result.push_back(maxStart); // Starting index of maximum subarray
    result.push_back(maxEnd);   // Ending index of maximum subarray

    // Return the results
    return result;
}
