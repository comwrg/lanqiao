#include <bits/stdc++.h>
using namespace std;

// 辗转相除法
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    cout << gcd(252, 105) << endl;

    return 0;
}