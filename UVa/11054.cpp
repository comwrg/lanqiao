#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

const int NMAX = 1e5;

// 思路巧妙，个人理解为整体法， 都看成2个村庄
int main() {
    int t;
    while (~scanf("%d", &t) and t) {
        ll last = 0, ans = 0;
        for (int i = 0; i < t; ++i) {
            int a;
            scanf("%d", &a);
            last += a;
            ans += abs(last);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
