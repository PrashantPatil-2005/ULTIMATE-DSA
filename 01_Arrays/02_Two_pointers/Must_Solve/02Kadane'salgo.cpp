#include <iostream>
#include <vector>
using namespace std;

int maxSubArrayBrute(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

#include <iostream>
#include <vector>
using namespace std;

int maxSubArrayKadane(vector<int>& nums) {
    int maxSoFar = nums[0];  // Holds max overall sum
    int currSum = nums[0];   // Holds max ending at current position

    for (int i = 1; i < nums.size(); i++) {
        // Either start fresh or extend the previous subarray
        currSum = max(nums[i], currSum + nums[i]);
        maxSoFar = max(maxSoFar, currSum);
    }

    return maxSoFar;
}
