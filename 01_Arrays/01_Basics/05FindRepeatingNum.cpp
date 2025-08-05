#include <iostream>
#include <unordered_set>
using namespace std;

// Brute: Nested loop → O(n^2), O(1)

// Better: Hashing → O(n), O(n)
int findDuplicate(int arr[], int n) {
    unordered_set<int> seen;
    for(int i = 0; i < n; i++) {
        if(seen.find(arr[i])!=seen.end()) return arr[i];
        seen.insert(arr[i]);
    }
    // for(int i = 0; i < n; i++) {
    //     if(seen.count(arr[i])) return arr[i];
    //     seen.insert(arr[i]);
    // }
    return -1;
}

// Optimal: Floyd's cycle detection → O(n), O(1)
int findDuplicateFloyd(int arr[], int n) {
    int slow = arr[0], fast = arr[0];
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while(slow != fast);

    fast = arr[0];
    while(slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

int main() {
    int arr[] = {1, 3, 4, 2, 2};
    int n = 5;
    cout << "Duplicate (Better): " << findDuplicate(arr, n) << endl;
    cout << "Duplicate (Optimal): " << findDuplicateFloyd(arr, n) << endl;
}
