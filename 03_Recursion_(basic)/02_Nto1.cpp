#include <iostream>
using namespace std;

//O(n)
void printDescending(int n) {
    if (n == 0) return;
    cout << n << " ";
    printDescending(n - 1);
}

int main() {
    int n;
    cin >> n;
    printDescending(n);
    return 0;
}
