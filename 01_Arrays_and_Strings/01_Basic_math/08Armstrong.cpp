#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int n) {
    int sum = 0, temp = n, digits = 0;

    // Count digits
    int t = n;
    while (t > 0) {
        digits++;
        t /= 10;
    }

    // Sum of digits raised to the power of digits
    t = n;
    while (t > 0) {
        int d = t % 10;
        sum += pow(d, digits);
        t /= 10;
    }

    return sum == temp;
}

int main() {
    int n;
    cin >> n;
    cout << (isArmstrong(n) ? "Armstrong" : "Not Armstrong") << endl;
    return 0;
}
