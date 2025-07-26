#include <iostream>
#include <climits>
using namespace std;

// Time: O(n) | Space: O(1)
void findMaxMin(int arr[], int n, int &mx, int &mn) {
    mx = INT_MIN;
    mn = INT_MAX;
    for(int i = 0; i < n; i++) {
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }
}

int main() {
    int arr[] = {4, 2, 7, 1, 9};
    int n = sizeof(arr)/sizeof(arr[0]), mx, mn;
    findMaxMin(arr, n, mx, mn);
    cout << "Max: " << mx << ", Min: " << mn << endl;
}
