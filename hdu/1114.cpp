#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int INF = 0x3f3f3f3f;
const int NMAX = 10001;
int t;
int weight;
int n;
int v[NMAX];
int w[NMAX];
int dp[NMAX];

int main() {
    rdIn("data.txt");

    scanf("%d", &t);
    while (t--) {
        int e, f;
        scanf("%d %d", &e, &f);
        weight = f - e;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &v[i], &w[i]);
        }

        memset(dp, INF, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = w[i]; j <= weight; ++j) {
                dp[j] = min(dp[j], dp[j-w[i]] + v[i]);
            }
        }
        if (dp[weight] == INF) {
            printf("This is impossible.");
        } else {
            printf("The minimum amount of money in the piggy-bank is %d.", dp[weight]);
        }
        printf("\n");
    }
  
    return 0;
}