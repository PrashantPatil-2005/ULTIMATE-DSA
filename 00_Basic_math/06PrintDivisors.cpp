#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getDivisors(int n) {
    vector<int> res;
    for(int i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(n/i!=i)
                res.push_back(n/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> divisors = getDivisors(n);
    for(int d : divisors) cout << d << " ";
    cout << endl;
    return 0;
}
