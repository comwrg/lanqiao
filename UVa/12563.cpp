/**
 * Jin Ge Jin Qu [h]ao, Rujia Liu's Present 6, UVa 12563
 *
 * Sample Input
 * 2 3 100 60 70 80 3 100 30 69 70
 *
 * Sample Outpu
 * Case 1: 2 758
 * Case 2: 3 777
 */
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }

const int INF = 0x3F3F3F3F;
const int T_JQ = 11 * 60 + 18;
const int T_MAX = 50 * 3*60 + T_JQ;

int n; // n <= 50
int t; // t <= 1e9
int data[50]; // data[i] <= 3*60 = 180
int dp[T_MAX];
int ts[T_MAX];

int main() {
    rdIn("data.txt");

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        memset(dp, 0, sizeof(dp));
        memset(ts, 0, sizeof(ts));

        cin >> n >> t;
        for (int j = 0; j < n; j++) {
            cin >> data[j];
        }

        for (int i = 0; i < n; i++) {
            for (int j = t; j > data[i]; j--) {
                int b = j - data[i];
                int k = dp[b] + 1;
                if (k > dp[j]) {
                    dp[j] = k;
                    ts[j] = ts[b] + data[i];
                } else if (k == dp[j]) {
                    ts[j] = max(ts[j], ts[b] + data[i]);
                }
            }
        }

        printf("Case %d: %d %d\n", i+1, dp[t]+1, ts[t]+T_JQ);

    }

    return 0;
}
