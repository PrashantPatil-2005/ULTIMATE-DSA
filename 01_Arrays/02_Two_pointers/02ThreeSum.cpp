#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        Time Complexity: O(n^2)
        - Sorting the array: O(n log n)
        - Outer loop runs n times, inner two-pointer loop also runs up to n times: O(n^2)
        - So total: O(n^2)

        Space Complexity: O(1) (excluding output)
        - No extra space used except for the result vector
        - If counting output, space is O(k) where k is number of triplets
    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        // Step 1: Sort the array to apply two-pointer technique
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // Step 2: Fix the first element (nums[i]) and find pairs for 0 - nums[i]
        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate values for nums[i] to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;       // Pointer starting just after i
            int right = n - 1;      // Pointer at the end of the array

            // Step 3: Use two pointers to find two numbers that sum to -nums[i]
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    // Found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate values for left and right
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    // Move both pointers inward
                    left++;
                    right--;
                }
                else if (sum < 0) {
                    // Need a larger sum → move left pointer forward
                    left++;
                }
                else {
                    // Need a smaller sum → move right pointer backward
                    right--;
                }
            }
        }

        return result;
    }
};
