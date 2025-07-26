#include <iostream>
#include <unordered_map>
using namespace std;

// Time: O(n) | Space: O(n)
bool checkEqual(int A[], int B[], int n) {
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) mp[A[i]]++;
    for(int i = 0; i < n; i++) {
        if(mp.find(B[i]) == mp.end()) return false;
        mp[B[i]]--;
        if(mp[B[i]] < 0) return false;
    }
    return true;
}

int main() {
    int A[] = {1, 2, 5, 4, 0};
    int B[] = {2, 4, 5, 0, 1};
    int n = 5;
    cout << (checkEqual(A, B, n) ? "Equal" : "Not Equal");
}
