#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    // Time Complexity: O(n)
    // Space Complexity: O(1)

    int n = nums.size(), i = n - 2;

    // Step 1: Find first decreasing element from end
    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;

    if (i >= 0) {
        // Step 2: Find element just greater than nums[i] from the end
        int j = n - 1;
        while (nums[j] <= nums[i])
            j--;
        // Step 3: Swap
        swap(nums[i], nums[j]);
    }

    // Step 4: Reverse the part after i
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
    cout << "Next Permutation: ";
    for (int x : nums) cout << x << " ";
    return 0;
}
