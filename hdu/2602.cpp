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

int main() {
    rdIn("data.txt");

    scanf("%d", &t);
    while (t--) {
        memset(dp, 0, sizeof(dp));

        scanf("%d %d", &n, &v);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &value[i]);
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &volume[i]);
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = v; j >= volume[i]; --j) {
                dp[j] = max(dp[j], dp[j-volume[i]] + value[i]);
            }
        }
        printf("%d\n", dp[v]);
    }
    return 0;
}