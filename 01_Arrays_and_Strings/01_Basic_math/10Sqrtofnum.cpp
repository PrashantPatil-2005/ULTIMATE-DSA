#include <iostream>
using namespace std;

int integerSqrt(int n) {
    int low = 0, high = n, ans = 0;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(1LL * mid * mid <= n) {
            ans = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << integerSqrt(n) << endl;
    return 0;
}
