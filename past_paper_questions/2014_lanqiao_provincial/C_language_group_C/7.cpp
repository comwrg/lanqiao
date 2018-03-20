#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int main() {

    for (int a = 1; a < 49; a++) {
        for (int b = 1; b < 49; b++) {
            int sum = 1225;
            sum -= a + a+1;
            sum -= b + b+1;
            sum += a * (a+1);
            sum += b * (b+1);
            if (sum == 2015) {
                cout << a << " " << b << endl;
            }
        }
    }

    return 0;
}