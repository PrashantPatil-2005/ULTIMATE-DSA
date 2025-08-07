#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        Time Complexity: O(n^3)
        - Sorting takes O(n log n)
        - First loop (i): O(n)
        - Second loop (j): O(n)
        - Two-pointer inside: O(n)
        => Total = O(n^3)

        Space Complexity: O(1) (excluding output)
        - Uses only constant extra space.
        - Output space = O(k) for k quadruplets
    */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Step 1: Sort the array

        for (int i = 0; i < n - 3; i++) {
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicates for j
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = 1LL * nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates for left and right
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    }
                    else if (sum < target) {
                        left++; // Need larger sum
                    }
                    else {
                        right--; // Need smaller sum
                    }
                }
            }
        }

        return result;
    }
};
