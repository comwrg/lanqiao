#include <bits/stdc++.h>
using namespace std;

/**
 *            |  0                              (i < 0 or j < 0)
 * dp[i][j] = |  dp[i-1][j-1] + 1               (i, j > 0, Xi == Yj)
 *            |  max(dp[i][j-1], dp[i-1][j])    (i, j > 0, Xi != Yj)
 */

int data_a[] = {1, 5, 2, 6, 8, 7};    const int len_a = sizeof(data_a) / sizeof(int);
int data_b[] = {2, 3, 5, 6, 9, 8, 4}; const int len_b = sizeof(data_b) / sizeof(int);

int dp[len_a][len_b];

int LCS(const int i, const int j) {
    if (i < 0 || j < 0) {
        return 0;
    }

    if (dp[i][j] > 0) {
        return dp[i][j];
    }

    if (data_a[i] == data_b[j]) {
        return dp[i][j] = LCS(i-1, j-1) + 1;
    } else {
        return dp[i][j] = max(LCS(i, j-1), LCS(i-1, j));
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
    cout << LCS(len_a-1, len_b-1) << endl;
    return 0;
}