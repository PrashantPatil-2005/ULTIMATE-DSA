#include <iostream>
using namespace std;

// Time: O(n) | Space: O(1)
void rotateByOne(int arr[], int n) {
    int temp = arr[n - 1];
    for(int i = n - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = temp;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    rotateByOne(arr, n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
