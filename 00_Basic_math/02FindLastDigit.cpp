#include <iostream>
using namespace std;

int lastDigit(int n) {
    return abs(n) % 10;
}

int main() {
    int n;
    cin >> n;
    cout << lastDigit(n) << endl;
    return 0;
}
