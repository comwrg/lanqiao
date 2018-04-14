/**
 * http://acm.hdu.edu.cn/showproblem.php?pid=1019
 */
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }
typedef long long LL;

LL gcd(LL a, LL b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

LL lcm(LL a, LL b) {
    return a*b / gcd(a, b);
}

int main() {
    rdIn("data.txt");

    int ln; scanf("%d", &ln);
    for (int _ = 0; _ < ln; _++) {
        int m; scanf("%d", &m);
        LL g = 0;
        for (int __ = 0; __ < m; __++) {
            int n; scanf("%d", &n);
            if (g == 0) {
                g = n;
            } else {
                g = lcm(g, n);
            }
        }
        printf("%d\n", g);
    }

    return 0;
}