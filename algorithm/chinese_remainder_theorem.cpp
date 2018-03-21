// 中国剩余定理

#include <bits/stdc++.h>
using namespace std;


int gcd_ex(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int r = gcd_ex(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return r;
}

void chinese_remainder_theorem(int data[][2], int len) {

}

int main() {
    int data[3][2] = {
            {2, 3},
            {3, 5},
            {2, 7},
    };
    chinese_remainder_theorem(data, 3);

    return 0;
}