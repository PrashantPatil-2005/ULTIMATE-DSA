#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        Time Complexity: O(n)
        - Each element is visited at most twice (start and end).

        Space Complexity: O(1)
        - Constant extra space used.
    */
    int longestSubarrayWithSumK(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0, end = 0;
        int sum = 0, maxLen = 0;

        while (end < n) {
            sum += nums[end];

            // Shrink window from start if sum exceeds k
            while (sum > k && start <= end) {
                sum -= nums[start];
                start++;
            }

            // Check if current window sum is k
            if (sum == k) {
                maxLen = max(maxLen, end - start + 1);
            }

            end++;
        }

        return maxLen;
    }
};
