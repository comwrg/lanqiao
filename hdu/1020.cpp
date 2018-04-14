/**
 * http://acm.hdu.edu.cn/showproblem.php?pid=1020
 */
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int main() {
    rdIn("data.txt");

    int n;
    while (~scanf("%d\n", &n)) {
        while (n--) {
            char ln[10000];
            gets(ln);
            int i = 0;
            while (ln[i] != '\0') {
                char basec = ln[i++];
                int times = 1;
                while (ln[i] == basec) {
                    i++;
                    times++;
                }

                if (times > 1) {
                    printf("%d", times);
                }
                printf("%c", basec);
            }
            printf("\n");
        }
    }

  
    return 0;
}