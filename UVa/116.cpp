/**
 * Unidirectional TSP, UVa 116
 *
 * Sample Input
 * 5 6 3 4 1 2 8 6 6 1 8 2 7 4 5 9 3 9 9 5 8 4 1 3 2 6 3 7 2 8 6 4 5 6 3 4 1 2 8 6 6 1 8 2 7 4 5 9 3 9 9 5 8 4 1 3 2 6 3 7 2 1 2 3 2 2 9 10 9 10
 *
 * Sample Output
 * 1 2 3 4 4 5
 * 16
 * 1 2 1 5 4 5
 * 11
 * 1 1
 * 19
 */
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }

int m, n; // m <= 10; n <= 100
int data[10][100];
int dp[10][100];

int handle_x(int x) {
    if (x == -1)
        x = m - 1;
    if (x == m)
        x = 0;
    return x;
}

int main() {
   rdIn("data.txt");

    while (cin >> m >> n) {
        memset(data, 0, sizeof(data));
        memset(dp, 0x3f, sizeof(dp));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> data[i][j];
            }
            dp[i][n-1] = data[i][n-1];
        }

        for (int j = n-1; j > 0; j--) {
            for (int i = 0; i < m; i++) {
                int above = handle_x(i-1);
                int below = handle_x(i+1);
                dp[above][j-1] = min(dp[above][j-1], dp[i][j] + data[above][j-1]);
                dp[i    ][j-1] = min(dp[i    ][j-1], dp[i][j] + data[i    ][j-1]);
                dp[below][j-1] = min(dp[below][j-1], dp[i][j] + data[below][j-1]);
            }
        }

        int x = 0;
        int vmin = 0x3f3f3f3f;
        for (int i = 0; i < m; i++) {
            if (dp[i][0] < vmin) {
                vmin = dp[i][0];
                x = i;
            }
        }

        // print path
        for (int y = 0; y < n; y++) {
            int arr[3];
            int xs[3] = {handle_x(x-1),
                         handle_x(x  ),
                         handle_x(x+1)};
            sort(xs, xs+3);
            for (int i = 0; i < 3; i++) {
                arr[i] = dp[xs[i]][y];
            }
            auto min_point = min_element(arr, arr+3);
            auto dis = distance(arr, min_point);
            x = xs[dis];
            if (y) {
                cout << " ";
            }
            cout << x+1;
        }
        cout << endl;
        cout << vmin << endl;
    }

    return 0;
}