#include <iostream>
using namespace std;

// Brute: Use visited array → O(n) time, O(n) space

// Optimal: Sum of 1 to n → O(n) time, O(1) space
int findMissing(int arr[], int n) {
    int total = (n * (n + 1)) / 2;
    int sum = 0;
    for(int i = 0; i < n - 1; i++)
        sum += arr[i];
    return total - sum;
}

int main() {
    int arr[] = {1, 2, 4, 5};
    int n = 5;
    cout << "Missing Number: " << findMissing(arr, n) << endl;
}
