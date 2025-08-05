// Given a sorted array and a target x:

// Floor of x:
// The largest value ≤ x

// Array: [1, 2, 4, 6, 8, 10]
// Target x = 5

// - Floor = 4 (largest ≤ 5)

// | Term        | Condition    | Result (Index) | Notes                           |
// | ----------- | ------------ | -------------- | ------------------------------- |
// | Lower Bound | `arr[i] ≥ x` | First ≥ x      | Same as **Ceil** (index)        |
// | Upper Bound | `arr[i] > x` | First > x      | Used to compute **count of x**  |
// | Floor       | `arr[i] ≤ x` | Last ≤ x       | Opposite direction of ceil      |
// | Ceil        | `arr[i] ≥ x` | First ≥ x      | Same as **lower bound** (index) |



#include <iostream>
#include <vector>
using namespace std;
// Returns the largest value <= x
int findFloor(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int floorVal = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] <= x) {
            floorVal = arr[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return floorVal;
}

int main() {
    vector<int> arr = {1, 2, 4, 6, 8, 10};
    int x = 5;

    int floorResult = findFloor(arr, x);

    cout << "Floor of " << x << " = " << floorResult << endl;

    return 0;
}
