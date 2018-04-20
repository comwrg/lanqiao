#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int data[101][2];
vector<int> tunnel[101];

int dfs(int ntrooper, int room = 1) {
    vector<int> ans {0};
    int rest = ntrooper - data[room][0];
    if (rest < 0)
        return -1;
    for (int i : tunnel[room]) {
        ans.push_back(dfs(rest, i));
    }
    return data[room][1] + *max_element(ans.begin(), ans.end());
}


int main() {
    rdIn("data.txt");

    int n, m;
    while (~scanf("%d %d", &n, &m) and ~n) {
        memset(data, 0, sizeof(data));
        memset(tunnel, 0 , sizeof(tunnel));

        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &data[i][0], &data[i][1]);
            data[i][0] = ceil(data[i][0] / 20.0);
        }
        for (int i = 1; i < n; ++i) {
            int room, dst;
            scanf("%d %d", &room, &dst);
            tunnel[room].push_back(dst);
        }
        printf("%d\n", dfs(m));
    }

    return 0;
}