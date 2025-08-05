// Optimal Approach using Unordered Map (Hash Map)
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <unordered_map>
using namespace std;

void countFrequencyOptimal(int arr[], int n) {
    unordered_map<int, int> freq;

    // Count frequency
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Print frequency
    cout << "\nOptimal Frequencies using Hash Map:\n";
    for (auto it : freq) {
        cout << it.first << " -> " << it.second << "\n";
    }
}

int main() {
    int arr[] =  { 2, 2, 1, 3, 2, 3,1,1,1,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countFrequencyOptimal(arr, n);

    return 0;
}
