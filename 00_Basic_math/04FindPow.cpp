#include <iostream>
using namespace std;

// Function to calculate x^n using Exponentiation by Squaring
long long power(int x, int n) {
    long long result = 1;

    while (n > 0) {
        if (n % 2 == 1) {
            // If n is odd: x^n = x * (x^2)^(n-1)/2
            result = result * x;     // use 1 x
            n = n - 1;               // reduce n by 1 to make it even
        }

        // Now n is even: x^n = (x^2)^(n/2)
        x = x * x;   // square the base
        n = n / 2;   // divide exponent by 2
    }

    return result;
}

int main() {
    int x, n;
    cout << "Enter base and exponent: ";
    cin >> x >> n;

    long long answer = power(x, n);
    cout << "Result: " << answer << endl;

    return 0;
}
