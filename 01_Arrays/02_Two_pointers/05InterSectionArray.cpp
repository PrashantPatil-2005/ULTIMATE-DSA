#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    // Time: O(n + m), Space: O(n)
    unordered_set<int> set1(nums1.begin(), nums1.end()); // Store all elements of nums1
    unordered_set<int> result;

    for (int num : nums2) {
        if (set1.count(num)) {
            result.insert(num); // Only add if num is in nums1
        }
    }

    return vector<int>(result.begin(), result.end()); // Convert set to vector
}

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> result = intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
