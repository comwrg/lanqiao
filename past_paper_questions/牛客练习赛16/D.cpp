#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int NMAX = 1e5 + 10;
// k base, b lucky number
int k, b, n;
int data[NMAX];
int dr_sum[NMAX];

int digital_root(int i) {
    return 1 + (i - 1) % (k - 1);
}

int main() {
    rdIn("data.txt");

    return 0;
}