#include <bits/stdc++.h>   // includes most headers (non-standard, but common in CP)
#include <numeric>         // specifically needed for std::gcd in C++17+

using namespace std;

// Your own GCD function (commented out)
// int gcd(int a, int b) {
//     while(b != 0) {
//         int rem = a % b;
//         a = b;
//         b = rem;
//     }
//     return a;
// }

int main() {
    int a, b;
    cin >> a >> b;

    // Using in-built C++17 gcd
    cout << std::gcd(a, b) << endl;

    return 0;
}
