#include <iostream>
using namespace std;

// Time: O(n) | Space: O(1)
int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++)
        if(arr[i] == key) return i;
    return -1;
}

int main() {
    int arr[] = {5, 3, 9, 1, 6};
    int n = sizeof(arr)/sizeof(arr[0]), key = 9;
    int index = linearSearch(arr, n, key);
    index != -1 ? cout << "Found at index " << index : cout << "Not Found";
}
