#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int NMAX = 1001;
int t;
int n, v;
int volume[NMAX];
int value[NMAX];
int dp[NMAX];
int dp1[NMAX][NMAX];

int foo(int i, int v) {
    if (v < 0)
        return -0x3f3f3f3f;
    if (i == 0)
        return 0;
    if (dp1[i][v] > -1)
        return dp1[i][v];
    return dp1[i][v] = max(foo(i-1, v),
                           foo(i-1, v-volume[i]) + value[i]);
}

int main() {
    rdIn("data.txt");

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &v);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &value[i]);
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &volume[i]);
        }

        // method one: loop
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            for (int j = v; j >= volume[i]; --j) {
                dp[j] = max(dp[j], dp[j-volume[i]] + value[i]);
            }
        }
        printf("%d\n", dp[v]);
        // ----

        // method two: recursive, slow than loop
        memset(dp1, -1, sizeof(dp1));
        printf("%d\n", foo(n, v));
        // ----

    }
    return 0;
}