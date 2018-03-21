#include <iostream>

using namespace std;


int qpow(int base, int n) {
    /**
     *   base**n (n is even)
     * = (base**n/2) * (base**n/2)
     */
    if (n == 1) {
        return base;
    }
    int r = 1;
    if (n & 1) {
        r *= base;
    }
    int q = qpow(base, n>>1);
    return r * q*q;
}

int main() {
    cout << qpow(10, 9) << endl;
    cout << qpow(9, 9) << endl;

    return 0;
}
