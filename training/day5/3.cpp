/**
 * http://acm.hdu.edu.cn/showproblem.php?pid=1243
 */
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int n;
map<char, int> scores;
char bullet[2048];
char enemy[2048];
int dp[2048][2048];



int lcs(const int i, const int j) {
    if (i < 0 or j < 0) {
        return 0;
    }
    if (dp[i][j] >= 0) {
        return dp[i][j];
    }
    if (bullet[i] == enemy[j]) {
        return dp[i][j] = scores.at(bullet[i]) + lcs(i - 1, j - 1);
    }
    return dp[i][j] = max(lcs(i - 1, j), lcs(i, j - 1));
}

int main() {
    rdIn("data.txt");

    while (~scanf("%d\n", &n)) {
        scores.clear();
        char chs[2048];
        scanf("%s", chs);
        for (int i = 0; i < n; i++) {
            int s;
            scanf("%d", &s);
            scores.insert(make_pair(chs[i], s));
        }
        scanf("%s", bullet);
        scanf("%s", enemy);
        int bullet_len = strlen(bullet);
        int enemy_len = strlen(enemy);

//--------------recursive, Timeout----------------
//        memset(dp, -1, sizeof(dp));
//        int s = lcs(bullet_len-1, enemy_len-1);
//------------------------------------------------

//-------------------AC---------------------------
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= bullet_len; i++) {
            for (int j = 1; j <= enemy_len; j++) {
                if (bullet[i-1] == enemy[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + scores.at(bullet[i-1]);
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        int s = dp[bullet_len][enemy_len];
//------------------------------------------------

        printf("%d\n", s);
    }

    return 0;
}