#include "SubarraySum.h"


vector<int> subarraySum(const vector<int>& nums, int target) {
  //   +=====================================================+
  //   |                 WRITE YOUR CODE HERE                |
  //   | Description:                                        |
  //   | - This function finds a subarray in 'nums' that     |
  //   |   sums up to the given 'target'.                    |
  //   | - It uses an unordered_map for quick look-up.       |
  //   | - It returns the indices of the start and end       |
  //   |   elements of the subarray.                         |
  //   |                                                     |
  //   | Return type: vector<int>                            |
  //   |                                                     |
  //   | Tips:                                               |
  //   | - 'sumIndex' stores cumulative sums and their       |
  //   |   indices.                                          |
  //   | - 'currentSum' keeps track of the sum up to index i.|
  //   | - Use 'find' method for quick look-up in map.       |
  //   | - Check output from Test.cpp in "User logs".        |
  //   +=====================================================+
  // Map to store cumulative sum up to all indices
    unordered_map<int, int> sumIndex;
    sumIndex[0] = -1; // Initialize with sum 0 at index -1 for edge case

    int currentSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        currentSum += nums[i]; // Update current sum

        // Check if currentSum - target exists in map
        if (sumIndex.find(currentSum - target) != sumIndex.end()) {
            // If found, return the start and end indices of the subarray
            return vector<int>{sumIndex[currentSum - target] + 1, i};
        }

        // If not found, store the current sum and its index
        sumIndex[currentSum] = i;
    }

    // Return empty vector if no subarray found
    return vector<int>{};
}
