#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char chs[1010];
        scanf("%s", chs);
        int len = strlen(chs);
        bool palindrom[1010][1010]; // 是不是回文串
        memset(palindrom, 0, sizeof(palindrom));
        for (int i = 0; i < len; ++i) {
            int l, r;
            for (int j = 0; j < 2; ++j) {
                l = r = i;
                if (j)
                    ++r;
                while (l >= 0 and r < len) {
                    if (chs[l] == chs[r]) 
                        palindrom[l][r] = true;
                    else
                        break;
                    --l;
                    ++r;
                }
            }
        }
        
        int dp[1010];
        int *p = &dp[1];
        for (int i = 0; i <= len; ++i)
            dp[i] = i;
        for (int i = 0; i < len; ++i) {
            for (int j = -1; j < i; ++j) {
                if (palindrom[j+1][i]) {
                    p[i] = min(p[i], p[j]+1);
                }
            }
        }
        printf("%d\n", dp[len]);

    }

    return 0;
}
