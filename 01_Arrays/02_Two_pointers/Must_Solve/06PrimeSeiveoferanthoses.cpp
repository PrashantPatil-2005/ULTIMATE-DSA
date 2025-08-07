#include <iostream>
#include <vector>
using namespace std;

void sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true); // Initially mark all as prime
    isPrime[0] = isPrime[1] = false;   // 0 and 1 are not prime

    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            // Mark all multiples of i as non-prime
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Print all primes
    cout << "Prime numbers up to " << n << " are:\n";
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    sieveOfEratosthenes(n);
    return 0;
}
