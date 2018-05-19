#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int NMAX = 25;
const int INF = 0x3f3f3f3f;
int ncase = 0;
int h, w, n;
int data[NMAX][NMAX];
int dp[NMAX][NMAX][NMAX][NMAX];

int getn(int left, int right, int top, int bottom) {
    int r = 0;
    for (int i = top; i < bottom; ++i) {
        for (int j = left; j < right; ++j) {
            if (data[i][j])
                ++r;
        }
    }
    return r;
}

int dfs(int left, int right, int top, int bottom) {
    int &d = dp[left][right][top][bottom];
    if (d)
        return d;
    int width = right - left;
    int height = bottom - top;
    int n = getn(left, right, top, bottom);
    if (n == 0)
        return INF;
    if (n == 1)
        return 0;

    int r = INF;
    for (int i = left+1; i < right; ++i) {
        r = min(r, dfs(left, i, top, bottom) + dfs(i, right, top, bottom) + height);
    }
    for (int i = top+1; i < bottom; ++i) {
        r = min(r, dfs(left, right, top, i) + dfs(left, right, i, bottom) + width);
    }
    return d = r;
}

int main() {
    while (~scanf("%d %d %d", &h, &w, &n)) {
        memset(data, 0, sizeof(data));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            data[x-1][y-1] = 1;
        }
        printf("Case %d: %d\n", ++ncase, dfs(0, w, 0, h)); 
    }

    return 0;
}
