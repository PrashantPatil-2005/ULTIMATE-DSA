// What is Upper Bound?
// Given a sorted array and a target value x,
// Upper Bound = first index where value > x

// Example:
// Array: [1, 2, 4, 4, 6, 8]
// Target x = 4
// We're looking for first value > 4 → which is 6
// Answer: index 4 (value = 6)

//  Mnemonic:
// “Upper bound skips all occurrences of x and gives the next greater value.”
// Upper Bound = arr[i] > x
// | Concept         | Condition    | Example (x = 4)     | Result           |
// | --------------- | ------------ | ------------------- | ---------------- |
// | **Lower Bound** | `arr[i] ≥ x` | First index of 4    | `2`              |
// | **Upper Bound** | `arr[i] > x` | First index after 4 | `4` (which is 6) |

#include <iostream>
#include <vector>
using namespace std;

//  Upper Bound: First index where arr[i] > x
int upperBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size(); // default if not found
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > x) {
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
    int ub = upperBound(arr, x);

    cout << "Upper Bound of " << x << ": ";
    if (ub < arr.size()) cout << "Index = " << ub << ", Value = " << arr[ub] << endl;
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

//     // Upper Bound (First index where value > x)
//     auto ub = upper_bound(arr.begin(), arr.end(), x);
//     if (ub != arr.end()) {
//         cout << "Upper Bound of " << x << ": Index = " << ub - arr.begin()
//              << ", Value = " << *ub << endl;
//     } else {
//         cout << "Upper Bound of " << x << ": Out of bounds" << endl;
//     }

//     return 0;
// }

// | Function      | Usage                                    | Returns                        |
// | ------------- | ---------------------------------------- | ------------------------------ |
// | `lower_bound` | `lower_bound(arr.begin(), arr.end(), x)` | Iterator to first `arr[i] ≥ x` |
// | `upper_bound` | `upper_bound(arr.begin(), arr.end(), x)` | Iterator to first `arr[i] > x` |
