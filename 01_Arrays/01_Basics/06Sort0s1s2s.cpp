#include <iostream>
using namespace std;

// Brute: Count 0s,1s,2s and overwrite → O(n), O(1)
// Optimal: 3-pointer DNF sort → O(n), O(1)
void sortColors(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;
    while(mid <= high) {
        if(arr[mid] == 0) swap(arr[low++], arr[mid++]);
        else if(arr[mid] == 1) mid++;
        else swap(arr[mid], arr[high--]);
    }
}

int main() {
    int arr[] = {0, 1, 2, 0, 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortColors(arr, n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
