#include <iostream>
using namespace std;

bool isPerfect(int n) {
    int sum = 1;
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            sum += i;
            if(i != n/i) sum += n/i;
        }
    }
    return n != 1 && sum == n;
}

int main() {
    int n;
    cin >> n;
    cout << (isPerfect(n) ? "Perfect Number" : "Not Perfect") << endl;
    return 0;
}
