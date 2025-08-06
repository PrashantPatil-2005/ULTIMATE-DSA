#include <iostream>
#include <algorithm>
using namespace std;

// Time: O(n) | Space: O(1)
void rotateByK(int arr[], int n, int k) {
    k %= n;
    reverse(arr, arr + n);
    reverse(arr, arr + k);
    reverse(arr + k, arr + n);
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int k = 2, n = 5;
    rotateByK(arr, n, k);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
