#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int main() {
    rdIn("data.txt");

    int n, m;
    while (~scanf("%d %d", &n, &m)) {
        if (n > m) {
            swap(n, m);
        }
        int ans;
        if (n == 1) {
            ans = m;
        } else if (n == 2) {
            ans = 4*(m/4) + 2*min(m%4, 2);
        } else {
            ans = ((m*n)+1)/2;
        }
        printf("%d\n", ans);
    }

    return 0;
}