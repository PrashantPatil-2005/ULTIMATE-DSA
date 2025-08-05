#include <iostream>
using namespace std;

bool isPalindrome(int n) {
    int original = n, reversed = 0;
    while(n != 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}

int main() {
    int n;
    cin >> n;
    cout << (isPalindrome(n) ? "Palindrome" : "Not Palindrome") << endl;
    return 0;
}
