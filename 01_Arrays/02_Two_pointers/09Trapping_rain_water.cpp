#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        Time Complexity: O(n)
        - Each element is visited at most once by either left or right pointer.

        Space Complexity: O(1)
        - No extra space used (excluding input array and result).
    */
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                // Water trapped at left depends on left_max
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    water += left_max - height[left];
                }
                left++;
            } else {
                // Water trapped at right depends on right_max
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    water += right_max - height[right];
                }
                right--;
            }
        }

        return water;
    }
};
