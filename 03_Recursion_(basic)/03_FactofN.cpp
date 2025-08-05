#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}


//void 
class Solution {
public:
    void factorialvoid(int n) {
        help(n, 1);
    }

private:
    void help(int n, int res) {
        if (n == 0) {
            cout << res << endl;
            return;
        }
        help(n - 1, res * n);
    }
};

int main() {
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}

