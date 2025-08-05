#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

// Brute: Sort entire array → O(n log n), Space: O(1)
int thirdLargestBrute(vector<int>& a) {
    sort(a.begin(), a.end(), greater<int>());

    for (int val : a) 
        cout << val << " ";
        
    cout << endl;

    return a.size() >= 3 ? a[2] : -1;
}

// Optimal: Single scan to find 3 largest → O(n), Space: O(1)
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
        } else if (num > third && num < second) {
            third = num;
        }
    }
    return third == INT_MIN ? -1 : third;
}

// Distinct Version: Returns 3rd distinct largest if exists → O(n log n), Space: O(n)
int thirdDistinctLargest(vector<int>& a) {
    set<int, greater<int>> s(a.begin(), a.end());  // sorted + unique
    if (s.size() < 3) return -1;
    auto it = s.begin();
    advance(it, 2);  // move to 3rd element
    return *it;
}

int main() {
    vector<int> arr = {10, 10, 5, 3, 20, 5};

    cout << "Brute Third Largest: " << thirdLargestBrute(arr) << endl;
    cout << "Optimal Third Largest: " << thirdLargestOptimal(arr) << endl;
    cout << "Distinct Third Largest: " << thirdDistinctLargest(arr) << endl;

    return 0;
}
