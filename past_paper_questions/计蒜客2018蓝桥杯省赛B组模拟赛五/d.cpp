#include <iostream>
using namespace std;

int pw(int x, int y) {
    if (!y) {
        return 1;
    }
    int res = pw(x*x, y/2);
    if (y & 1) {
        res = res * x;
    }
    return res;
}

int main() {
    int x, y, p;
//    cin >> x >> y >> p;
    x = 2; y = 4;
    cout << pw(x, y) << endl;
    return 0;
}
