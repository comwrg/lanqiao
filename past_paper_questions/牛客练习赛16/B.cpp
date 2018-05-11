#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int NMAX = 1e5;
int n;
int arr[2*NMAX];
// 开一个下标可以为负数的数组, 参考 https://blog.csdn.net/finalcsdn/article/details/80113886
int *t = arr+NMAX;

int main() {
    rdIn("data.txt");

    while (~scanf("%d", &n)) {
        memset(arr, 0, sizeof(arr));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int v;
            scanf("%d", &v);
            if (i < n/2) {
                v = ++t[v-i];
            } else {
                v = ++t[v-(n-1-i)];
            }
            ans = max(ans, v);
        }
        printf("%d\n", n-ans);
    }

    return 0;
}