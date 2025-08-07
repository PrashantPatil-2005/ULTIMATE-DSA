#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> unionOfArrays(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> unionSet;

    // Insert elements of first array
    for (int num : arr1) {
        unionSet.insert(num);
    }

    // Insert elements of second array
    for (int num : arr2) {
        unionSet.insert(num);
    }

    // Convert set to vector
    vector<int> result(unionSet.begin(), unionSet.end());
    return result;
}

/*
Time Complexity: O(n + m)
- n: size of arr1
- m: size of arr2
- Each insertion in unordered_set is O(1) on average

Space Complexity: O(n + m)
- Extra space used by the set to store union of both arrays
*/

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {4, 5, 6, 7, 8};

    vector<int> unionResult = unionOfArrays(arr1, arr2);

    cout << "Union of arrays: ";
    for (int num : unionResult) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
