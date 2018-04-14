/**
 * http://acm.hdu.edu.cn/showproblem.php?pid=1021
 */
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }
typedef unsigned long long ULL;


int main() {
    rdIn("data.txt");

    int n;
    int data[] = {1, 2, 0, 2, 2, 1, 0, 1};
    while (~scanf("%d", &n)) {
        if (data[n%8]) {
            printf("no");
        } else {
            printf("yes");
        }
        printf("\n");
    }


    return 0;
}
/**
 * 0 7 % 3 = 1;
 * 1 11 % 3 = 2;
 * 2 1+2) % 3 = 0
 * 3 2+0) % 3 = 2
 * 4 2+0) % 3 = 2
 * 5 2+2) % 3 = 1
 * 6 1+2) % 3 = 0
 * 7 1+0) % 3 = 1
 *
 * 8 1+0) % 3 = 1
 * 9 1+1) % 3 = 2
 * 10 1+2) % 3 = 0
 */