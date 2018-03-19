/**
 * http://acm.hdu.edu.cn/showproblem.php?pid=1016
 */
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int cas = 0;
int data[20];
bool mark[20];
int n;

bool prime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void handle(int index = 1) {
    if (index == n) {
        if (!prime(data[0] + data[n-1])) {
            return;
        }
        int i;
        for (i = 0; i < n-1; i++) {
            printf("%d ", data[i]);
        }
        printf("%d\n", data[i]);
        return;
    }

    for (int i = 2; i <= n; i++) {
        if (!mark[i] and prime(i + data[index-1])) {
            mark[i] = true;
            data[index] = i;
            handle(index + 1);
            mark[i] = false;
        }
    }
}

int main() {
    rdIn("data.txt");

    while (~scanf("%d", &n)) {
        printf("Case %d:\n", ++cas);
        data[0] = 1;
        memset(mark, 0, sizeof(mark));

        handle();

        printf("\n");
    }
    return 0;
}