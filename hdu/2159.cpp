#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int INF = 0x3f3f3f3f;
const int NMAX = 100;
// n 需要的经验值
// m 忍耐度
// k 怪的种数
// s 最多的杀怪数
int n, m, k, s;
// 加的经验值
int experience[NMAX];
// 减的忍耐度
int endurance[NMAX];
// dp[i][0] 是 经验值， dp[i][1] 是 杀怪数
int dp[NMAX][2];

int main() {
    rdIn("data.txt");

    while (~scanf("%d %d %d %d", &n, &m, &k ,&s)) {
        for (int i = 0; i < k; ++i) {
            scanf("%d %d", &experience[i], &endurance[i]);
        }

        memset(dp, 0, sizeof(dp));
        int m_min = INF;
        for (int i = 0; i < k; ++i) {
            for (int j = endurance[i]; j <= m; ++j) {
                if (dp[j-endurance[i]][0] + experience[i] > dp[j][0]) {
                    dp[j][0] = dp[j-endurance[i]][0] + experience[i];
                    dp[j][1] = dp[j-endurance[i]][1] + 1;
                }

                if (dp[j][0] >= n and dp[j][1] <= s) {
                    m_min = min(m_min, j);
                }
            }
        }
        if (m_min > m) {
            printf("-1");
        } else {
            printf("%d", m - m_min);
        }
        printf("\n");
    }

    return 0;
}