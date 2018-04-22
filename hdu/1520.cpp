#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int NMAX = 6001;
const int INF = 0x3f3f3f3f;
int n;
int rating[NMAX]; // not use 0th
vector<int> relation[NMAX];
int dp[NMAX][2];

int dfs(int index, int status, int father) {
    if (dp[index][status] != INF)
        return dp[index][status];
    if (status) {
        // come
        dp[index][status] = rating[index];
        for (int child : relation[index]) {
            if (child != father)
                dp[index][status] += dfs(child, 0, index);
        }
    } else {
        // not come
        dp[index][status] = 0;
        for (int child : relation[index]) {
            if (child != father)
                dp[index][status] += max(dfs(child, 0, index), dfs(child, 1, index));
        }
    }
    return dp[index][status];
}

int main() {
    rdIn("data.txt");

    while (~scanf("%d", &n)) {
        memset(dp, INF, sizeof(dp));
        for (int i = 1; i < NMAX; ++i)
            relation[i].clear();

        for (int i = 1; i <= n; ++i) {
            scanf("%d", &rating[i]);
        }
        int l, k;
        while (~scanf("%d %d", &l, &k) and l) {
            relation[l].push_back(k);
            relation[k].push_back(l);
        }

        printf("%d\n", max(dfs(1, 0, -1), dfs(1, 1, -1)));

    }

    return 0;
}