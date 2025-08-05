#include <iostream>
#include <unordered_map>
using namespace std;

// Time: O(n + m) | Space: O(n)
bool isSubset(int A[], int B[], int n, int m) {
    unordered_map<int, int> freq;
    for(int i = 0; i < n; i++) freq[A[i]]++;
    for(int i = 0; i < m; i++) {
        if(freq[B[i]] == 0) return false;
        freq[B[i]]--;
    }
    return true;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {1, 2, 3};
    int n = 5, m = 3;
    cout << (isSubset(A, B, n, m) ? "Yes" : "No");
}
