#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

bool valid(int n) {
    long long n3 = pow(n, 3);
    long long nn = n, nn3 = n3;
    while (n) {
        int i = n3 % 10; n3 /= 10;
        int j = n % 10;  n /= 10;
        if (i != j) {
            return false;
        }
    }
    cout << nn << " " << nn3 << endl;
    return true;
}

int main() {
    int n = 0;
    for (int i = 1; i <= 10000; i++) {
        if (valid(i)) {
            n++;
        }
    }
    cout << endl;
    cout << n << endl;
  
    return 0;
}