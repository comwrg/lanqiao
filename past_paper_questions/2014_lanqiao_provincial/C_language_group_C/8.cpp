#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int main() {
    rdIn("data.txt");

    int n;
    while (~scanf("%d", &n)) {
        int r = n;
        while (n > 2) {
            n -= 3;
            r++;
            n++;
        }
        cout << r << endl;
    }

    return 0;
}