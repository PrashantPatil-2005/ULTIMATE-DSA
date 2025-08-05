//  What is Lower Bound?
// Given a sorted array and a target value x,
// Lower Bound = first index where value ≥ x

// Example:
// Array: [1, 2, 4, 4, 6, 8]
// Target x = 5
// We're looking for first value ≥ 5 → which is 6
// Answer: index 4 (value = 6)

//  Mnemonic:
// “Lower bound is the first place where x can be inserted without violating the order.”
// Lower Bound = First place where arr[i] ≥ x

// | Concept         | Condition    | Example (x = 4)     | Result           |
// | --------------- | ------------ | ------------------- | ---------------- |
// | **Lower Bound** | `arr[i] ≥ x` | First index of 4    | `2`              |
// | **Upper Bound** | `arr[i] > x` | First index after 4 | `4` (which is 6) |


#include <iostream>
#include <vector>
using namespace std;

//  Lower Bound: First index where arr[i] >= x
int lowerBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size(); // default if not found
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 5, 6};

    int x = 4;
    int lb = lowerBound(arr, x);

    cout << "Lower Bound of " << x << ": ";
    if (lb < arr.size()) cout << "Index = " << lb << ", Value = " << arr[lb] << endl;
    else cout << "Out of bounds\n";

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>  // for lower_bound, upper_bound

// using namespace std;

// int main() {
//     vector<int> arr = {1, 2, 2, 2, 3, 5, 6};
//     int x = 4;

//     // Lower Bound (First index where value >= x)
//     auto lb = lower_bound(arr.begin(), arr.end(), x);
//     if (lb != arr.end()) {
//         cout << "Lower Bound of " << x << ": Index = " << lb - arr.begin()
//              << ", Value = " << *lb << endl;
//     } else {
//         cout << "Lower Bound of " << x << ": Out of bounds" << endl;
//     }

//     return 0;
// }

// | Function      | Usage                                    | Returns                        |
// | ------------- | ---------------------------------------- | ------------------------------ |
// | `lower_bound` | `lower_bound(arr.begin(), arr.end(), x)` | Iterator to first `arr[i] ≥ x` |
// | `upper_bound` | `upper_bound(arr.begin(), arr.end(), x)` | Iterator to first `arr[i] > x` |
