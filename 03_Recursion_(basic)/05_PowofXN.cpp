// #include <iostream>
// using namespace std;

// int power(int x, int n) {
//     if (n == 0) return 1;
//     return x * power(x, n - 1);
// }

// int main() {
//     int x, n;
//     cin >> x >> n;
//     cout << power(x, n);
//     return 0;
// }
#include <iostream>
using namespace std;

int fastPower(int x, int n) {
    if (n == 0) return 1;
    int half = fastPower(x, n / 2);
    if (n % 2 == 0) return half * half;
    else return x * half * half;
}

int main() {
    int x, n;
    cin >> x >> n;
    cout << fastPower(x, n);
    return 0;
}
