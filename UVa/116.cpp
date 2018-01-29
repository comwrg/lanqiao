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
int path[10][100];

int handle_x(int x) {
    if (x == -1)
        x = m - 1;
    if (x == m)
        x = 0;
    return x;
}

int foo(int x, int y) {
    x = handle_x(x);
    if (y == n-1)
        return dp[x][y] = data[x][y];
    if (dp[x][y])
        return dp[x][y];
    int arr[3];
    arr[0] = foo(x-1, y+1);
    arr[1] = foo(x  , y+1);
    arr[2] = foo(x+1, y+1);
    auto min_point = min_element(arr, arr+3);
    dp[x][y] = data[x][y] + *min_point;
    return dp[x][y];
}

int main() {
   rdIn("data.txt");

    while (cin >> m >> n) {
        memset(data, 0, sizeof(data));
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> data[i][j];
            }
        }

        int x = 0;
        for (int i = 0; i < m; i++) {
            int v = foo( m, 0);
            path[i][0] = i;
            if (dp[x][0] > v) {
                x = i;
            }
        }
        int xx = x;

        // print path
        for (int y = 0; y < n; y++) {
            if (y != 0) {
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
            }
            cout << x + 1;
            if (y != n-1)
                cout << " ";
        }
        cout << endl;
        cout << dp[xx][0] << endl;
    }

    return 0;
}