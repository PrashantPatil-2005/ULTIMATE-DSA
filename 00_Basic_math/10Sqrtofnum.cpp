#include <iostream>
#include<cmath>
using namespace std;

int squareRoot(int n) {
    int i = 1;
    while (i * i <= n) {
        i++;
    }
    return i - 1;
}

double squareRootInbuilt(double num) {
    if (num < 0) {
        cout << "Square root of negative number is not real." << endl;
        return -1;
    }
    return sqrt(num); // Built-in function
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num < 0)
        cout << "Square root of negative number is not real.";
    else
        cout << "Square root is: " << squareRoot(num) << endl;

        cout<<squareRootInbuilt(num)<<endl;
    return 0;
}
