#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int n) {
    int sum = 0, temp = n;
    int digits = log10(n) + 1;
    while(n > 0) {
        int d = n % 10;
        sum += pow(d, digits);
        n /= 10;
    }
    return sum == temp;
}

int main() {
    int n;
    cin >> n;
    cout << (isArmstrong(n) ? "Armstrong" : "Not Armstrong") << endl;
    return 0;
}
