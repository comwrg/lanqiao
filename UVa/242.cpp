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
            queue<int> que;
            set<int> dp;
            while (w--) {
                int v; scanf("%d", &v);
                data.push_back(v);
                que.push(v);
                dp.insert(v);
            }
            for (int i = 0; i < s-1; ++i) {
                int size = que.size();
                while (size--) {
                    int v = que.front(); que.pop();
                    for (int i : data) {
                        int d = v + i;
                        dp.insert(d);
                        que.push(d);
                    }
                }
            }
            int last = 0;
            int seq = 0;
            for (int i : dp) {
                if (i - last == 1) {
                    ++seq;
                } else {
                    break;
                }
                last = i;
            }
            if (seq >= ans) {
                ans = seq;
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
