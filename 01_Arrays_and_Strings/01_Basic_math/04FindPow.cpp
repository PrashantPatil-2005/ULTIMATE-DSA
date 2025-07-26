#include <iostream>
using namespace std;

long long power(int x, int n) {
    long long res = 1;
    while(n > 0) {
        if(n % 2 == 1)
            res *= x;
        x *= x;
        n /= 2;
    }
    return res;
}

int main() {
    int x, n;
    cin >> x >> n;
    cout << power(x, n) << endl;
    return 0;
}
