#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        Time Complexity: O(n)
        - Each element is visited once by the fast pointer.

        Space Complexity: O(1)
        - No extra space used, in-place modification.
    */
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0; // slow pointer (index of last unique element)

        for (int j = 1; j < nums.size(); j++) {
            // When a new unique element is found
            if (nums[j] != nums[i]) {
                i++;              // Move slow pointer
                nums[i] = nums[j]; // Copy the unique value
            }
        }

        return i + 1; // Length of array with unique elements
    }
};
