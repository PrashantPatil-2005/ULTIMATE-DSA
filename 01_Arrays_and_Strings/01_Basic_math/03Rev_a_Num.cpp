#include <iostream>
using namespace std;

//O(n)
int reverseNum(int n) {
    int rev = 0;
    while(n != 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

int main() {
    int n;
    cin >> n;
    cout << reverseNum(n) << endl;
    return 0;
}
