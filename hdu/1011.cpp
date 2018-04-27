#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int NMAX = 101;
int m;
int data[NMAX][2];
vector<int> tunnel[NMAX];
int dp[NMAX][NMAX];
bool arrived[NMAX];

void dfs(int room) {
    arrived[room] = true;
    for (int i = data[room][0]; i <= m; ++i) {
        dp[room][i] = data[room][1];
    }

    for (int dst : tunnel[room]) {
        if (arrived[dst])
            continue;
        dfs(dst);
        for (int i = m; i >= 0; --i) { // give room i people
            for (int j = 1; j <= i - data[room][0]; ++j) { // give dst j people. i-j >= data[room][0] -> j <= i-data[room][0]
                dp[room][i] = max(dp[room][i], dp[room][i-j] + dp[dst][j]);
            }
        }
    }
}


int main() {
    rdIn("data.txt");

    int n;
    while (~scanf("%d %d", &n, &m) and ~n) {
        memset(data, 0, sizeof(data));
        memset(dp, 0, sizeof(dp));
        memset(arrived, 0, sizeof(arrived));
        for (auto &i : tunnel)
            i.clear();

        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &data[i][0], &data[i][1]);
            data[i][0] = ceil(data[i][0] / 20.0);
        }
        for (int i = 1; i < n; ++i) {
            int room, dst;
            scanf("%d %d", &room, &dst);
            tunnel[room].push_back(dst);
            tunnel[dst].push_back(room);
        }
        if (m)
            dfs(1);
        printf("%d\n", dp[1][m]);
    }

    return 0;
}