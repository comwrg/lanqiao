#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int NMAX = 101;
int data[NMAX][2];
vector<int> tunnel[NMAX];
int dp[NMAX][NMAX];

int dfs(int room, int ntrooper, int next = 0) {
    int rest = ntrooper - data[room][0];
    if (rest < 0 or (data[room][0] == 0 and rest < 1))
        return 0;

    if (dp[room][ntrooper])
        return dp[room][ntrooper];

    int r = 0;
    for (int i = next; i < tunnel[room].size(); ++i) {
        int dst = tunnel[room].at(i);
        for (int send = 0; send <= rest; ++send) {
            r = max(r, dfs(room, rest-send, i+1) + dfs(dst, send));
        }
    }
    r += data[room][1];
    if (next == 0)
        dp[room][ntrooper] = r;
    return r;
}


int main() {
    rdIn("data.txt");

    int n, m;
    while (~scanf("%d %d", &n, &m) and ~n) {
        memset(data, 0, sizeof(data));
        memset(dp, 0, sizeof(dp));
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
        }
        printf("%d\n", dfs(1, m));
    }

    return 0;
}