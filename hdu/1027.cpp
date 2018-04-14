/**
 * http://acm.hdu.edu.cn/showproblem.php?pid=1027
 */
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int n, m;
int data[10000];

void show() {
    int i;
    for (i = 0; i < n-1; i++) {
        printf("%d ", data[i]);
    }
    printf("%d\n", data[i]);
}

int main() {
    rdIn("data.txt");

    while (~scanf("%d %d", &n, &m)) {
        for (int i = 0; i < n; i++) {
            data[i] = i + 1;
        }
        m--;
        while (m--) {
            next_permutation(data, data+n);
        }
        show();
    }

    return 0;
}