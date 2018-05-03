/**
 * The Tower of Babylon, UVa 437
 *
 * Sample Input
 * 1 10 20 30 2 6 8 10 5 5 5 7 1 1 1 2 2 2 3 3 3 4 4 4 5 5 5 6 6 6 7 7 7 5 31 41 59 26 53 58 97 93 23 84 62 64 33 83 27 0
 *
 * Sample Output
 *  Case 1: maximum height = 40
 *  Case 2: maximum height = 21
 *  Case 3: maximum height = 28
 *  Case 4: maximum height = 342
 */
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }

int n;
int data[30][3];
int dp[30][3];
int ncase = 0;

void index2side(int i, int j, int &x, int &y) {
    switch (j) {
        case 0:
            x = data[i][1]; y = data[i][2];
            break;
        case 1:
            x = data[i][0]; y = data[i][2];
            break;
        case 2:
            x = data[i][0]; y = data[i][1];
            break;
    }
}

int foo(int index, int h) {
    if (dp[index][h] > 0)
        return dp[index][h];
    int index_side_1, index_side_2; index2side(index, h, index_side_1, index_side_2);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int i_side_1, i_side_2; index2side(i, j, i_side_1, i_side_2);
            if ((i_side_1 < index_side_1 && i_side_2 < index_side_2)
             || (i_side_1 < index_side_2 && i_side_2 < index_side_1)) {
                mx = max(mx, foo(i, j));
            }
        }
    }
    dp[index][h] = data[index][h] + mx;
    return dp[index][h];
}

int main() {
    rdIn("data.txt");


    while (cin >> n) {
        if (n <= 0)
            continue;

        memset(data, 0, sizeof(data));
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++) {
            cin >> data[i][0] >> data[i][1] >> data[i][2];
        }

        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                mx = max(mx, foo(i, j));
            }
        }
        printf("Case %d: maximum height = %d\n", ++ncase, mx);
    }

  
    return 0;
}
