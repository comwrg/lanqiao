/**
 * http://acm.hdu.edu.cn/showproblem.php?pid=1000
 */
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int main() {
    rdIn("data.txt");

    int a, b;
    while (~scanf("%d %d", &a, &b)) {
        printf("%d\n", a+b);
    }
  
  
    return 0;
}