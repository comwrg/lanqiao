#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int NMAX = 0x3f3f;
int c;
int n;
int dp[NMAX];

void pack_zero_one(int cost, int value) {
    for (int i = n; i >= cost; --i)
        dp[i] = max(dp[i], dp[i-cost]+value);
}

void pack_complete(int cost, int value) {
    for (int i = cost; i <= n; ++i)
        dp[i] = max(dp[i], dp[i-cost]+value);
}

void pack_multiple(int cost, int value, int amount) {
    if (cost * amount >= n) {
        pack_complete(cost, value);
    } else {
        // 没优化的版本
//        for (int i = 0; i < amount; ++i) {
//            pack_zero_one(cost, value);
//        }
        // ----
        // 二进制优化后的版本
        for (int i = 1; i < amount; amount -= i, i <<= 1) {
            pack_zero_one(i*cost, i*value);
        }
        pack_zero_one(amount*cost, amount*value);
        // ----
    }
}

int main() {
    rdIn("data.txt");

    scanf("%d", &c);
    while (c--) {
        int cost[NMAX];
        int value[NMAX];
        int amount[NMAX];
        int m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &cost[i], &value[i], &amount[i]);
        }

        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; ++i) {
            pack_multiple(cost[i], value[i], amount[i]);
        }
        printf("%d\n", dp[n]);
    }

  
    return 0;
}