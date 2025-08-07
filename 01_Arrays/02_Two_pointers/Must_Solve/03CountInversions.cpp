#include <iostream>
#include <vector>
using namespace std;

// Time: O(n^2), Space: O(1)
int countInversionsBrute(vector<int>& arr) {
    int n = arr.size(), count = 0;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) count++;
        }
    }
    return count;
}

int main() {
    vector<int> arr = {8, 4, 2, 1};
    cout << "Inversions: " << countInversionsBrute(arr) << endl;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Merge function that also counts inversions
int merge(vector<int>& arr, int low, int mid, int high) {
    int count = 0;
    vector<int> temp;
    int i = low, j = mid+1;

    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            count += (mid - i + 1); // All remaining elements in left part are greater
        }
    }
    while(i <= mid) temp.push_back(arr[i++]);
    while(j <= high) temp.push_back(arr[j++]);

    for(int k = low; k <= high; k++)
        arr[k] = temp[k - low];

    return count;
}

// Merge sort with inversion count
int mergeSort(vector<int>& arr, int low, int high) {
    if(low >= high) return 0;
    int mid = (low + high) / 2;
    int inv = 0;
    inv += mergeSort(arr, low, mid);
    inv += mergeSort(arr, mid+1, high);
    inv += merge(arr, low, mid, high);
    return inv;
}

// Time: O(n log n), Space: O(n)
int countInversionsOptimal(vector<int>& arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {8, 4, 2, 1};
    cout << "Inversions: " << countInversionsOptimal(arr) << endl;
    return 0;
}
