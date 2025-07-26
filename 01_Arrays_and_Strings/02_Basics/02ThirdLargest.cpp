#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute: Sort entire array → O(n log n), Space: O(1)
int thirdLargestBrute(vector<int>& a) {
    sort(a.begin(), a.end(), greater<int>());
    return a.size() >= 3 ? a[2] : -1;
}

// Optimal: Single scan to find 3 max → O(n), Space: O(1)
int thirdLargestOptimal(vector<int>& a) {
    int first = INT_MIN, second = INT_MIN, third = INT_MIN;
    for (int num : a) {
        if (num > first) {
            third = second;
            second = first;
            first = num;
        } else if (num > second && num < first) {
            third = second;
            second = num;
        } else if (num > third && num < second)
            third = num;
    }
    return third == INT_MIN ? -1 : third;
}

int main() {
    vector<int> arr = {4, 7, 1, 3, 9};
    cout << "Brute Third Largest: " << thirdLargestBrute(arr) << endl;
    cout << "Optimal Third Largest: " << thirdLargestOptimal(arr) << endl;
}
