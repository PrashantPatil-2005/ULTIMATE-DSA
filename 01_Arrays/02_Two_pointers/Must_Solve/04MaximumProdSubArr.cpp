#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Time: O(N^2), Space: O(1)
int maxProductBruteForce(vector<int>& nums) {
    int n = nums.size();
    int maxProd = INT_MIN;

    for (int i = 0; i < n; ++i) {
        int prod = 1;
        for (int j = i; j < n; ++j) {
            prod *= nums[j];
            maxProd = max(maxProd, prod);
        }
    }
    return maxProd;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum Product (Brute Force): " << maxProductBruteForce(nums) << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time: O(N), Space: O(1)
int maxProductOptimal(vector<int>& nums) {
    int n = nums.size();
    int maxProd = nums[0];
    int currMax = nums[0];
    int currMin = nums[0];

    for (int i = 1; i < n; ++i) {
        if (nums[i] < 0)
            swap(currMax, currMin);

        currMax = max(nums[i], currMax * nums[i]);
        currMin = min(nums[i], currMin * nums[i]);

        maxProd = max(maxProd, currMax);
    }
    return maxProd;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum Product (Optimal): " << maxProductOptimal(nums) << endl;
    return 0;
}
