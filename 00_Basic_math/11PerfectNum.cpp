#include <iostream>
using namespace std;

bool isPerfect(int n) {
    if (n <= 1) return false;

    int sum = 1; // 1 is always a proper divisor
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i)
                sum += n / i;
        }
    }
    return sum == n;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPerfect(num))
        cout << num << " is a perfect number.";
    else
        cout << num << " is not a perfect number.";

    return 0;
}
