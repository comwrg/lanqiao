#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int s, n;

int main() {
    while (~scanf("%d", &s) and s) {

        int ans = 0;
        vector<int> vans;
        scanf("%d", &n);
        while (n--) {
            int w; scanf("%d", &w);
            vector<int> data;
            while (w--) {
                int v; scanf("%d", &v);
                data.push_back(v);
            }
            int dp[0xfffff];
            dp[0] = 0;
            int n = 0;
            while (++n) {
                dp[n] = 0x3f3f3f3f;
                for (int i : data) {
                    if (n - i >= 0)
                        dp[n] = min(dp[n], dp[n-i] + 1);
                }
                if (dp[n] > s) {
                    --n;
                    break;
                }
            }

            if (n > ans) {
                ans = n;
                vans = data;
            } else if (n == ans) {
                auto comp = [](vector<int> data, vector<int> vans) {
                    if (data.size() > vans.size())
                        return true;
                    if (data.size() < vans.size())
                        return false;
                    sort(data.begin(), data.end(), greater<int>());
                    sort(vans.begin(), vans.end(), greater<int>());
                    return data > vans;
                };
                if (comp(vans, data))
                    vans = data;
            }
        }
        printf("max coverage =%4d :", ans);
        for (int i : vans)
            printf("%3d", i);
        printf("\n");
    }


    return 0;
}
