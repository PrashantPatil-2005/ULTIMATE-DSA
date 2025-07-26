#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void mergeSort(vector<int> &arr, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        // Divide
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge
        merge(arr, left, mid, right);
    }

private:
    void merge(vector<int> &arr, int left, int mid, int right) {
        vector<int> temp;
        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }

        while (i <= mid) {
            temp.push_back(arr[i++]);
        }

        while (j <= right) {
            temp.push_back(arr[j++]);
        }

        // Copy back to original array
        for (int k = left; k <= right; k++) {
            arr[k] = temp[k - left];
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    sol.mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
