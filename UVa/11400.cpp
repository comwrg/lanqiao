#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct node {
    int v, // 电压
        k, // 电源费
        c, // 费用
        l; // 数量
    bool operator<(const node &rhs) {
        return v < rhs.v;
    }
} data[1010];


int main() {
    int t, dp[1010], s[1010];
    while (~scanf("%d", &t) and t) {
        s[0] = dp[0] = 0;
        for (int i = 1; i <= t; ++i) {
            scanf("%d %d %d %d", &data[i].v, &data[i].k, &data[i].c, &data[i].l);
        }
        sort(data+1, data+t+1);
        for (int i = 1; i <= t; ++i) {
            s[i] = s[i-1] + data[i].l;
            dp[i] = dp[i-1] + data[i].k + data[i].c*data[i].l;
        }
        for (int i = 1; i <= t; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] = min(dp[i], dp[j] + data[i].k + (s[i]-s[j])*data[i].c);
            }
        }
        printf("%d\n", dp[t]);
    }

    return 0;
}
