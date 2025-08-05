// Given a sorted array and a target x:

//  Ceil of x:
// The smallest value ≥ x

// Array: [1, 2, 4, 6, 8, 10]
// Target x = 5

// - Ceil = 6 (smallest ≥ 5)

// | Term        | Condition    | Result (Index) | Notes                           |
// | ----------- | ------------ | -------------- | ------------------------------- |
// | Lower Bound | `arr[i] ≥ x` | First ≥ x      | Same as **Ceil** (index)        |
// | Upper Bound | `arr[i] > x` | First > x      | Used to compute **count of x**  |
// | Floor       | `arr[i] ≤ x` | Last ≤ x       | Opposite direction of ceil      |
// | Ceil        | `arr[i] ≥ x` | First ≥ x      | Same as **lower bound** (index) |

#include <iostream>
#include <vector>
using namespace std;
// Returns the smallest value >= x
int findCeil(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ceilVal = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= x) {
            ceilVal = arr[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ceilVal;
}

int main() {
    vector<int> arr = {1, 2, 4, 6, 8, 10};
    int x = 5;

    int ceilResult = findCeil(arr, x);

    std::cout << "Ceil of " << x << " = " << ceilResult << std::endl;

    return 0;
}
