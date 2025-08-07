#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        Time Complexity: O(n)
        - Each element is visited once from both ends.

        Space Complexity: O(1)
        - Only constant extra space used.
    */
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            // Calculate area between left and right lines
            int h = min(height[left], height[right]);
            int w = right - left;
            maxArea = max(maxArea, h * w);

            // Move the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};
