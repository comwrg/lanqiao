#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int main() {
    rdIn("data.txt");

    int t;
    scanf("%d", &t);
    int casen = 0;
    while (t--) {
        int data[100000];
        int dp  [100000];
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", data+i);
        }

        int start, end;
        int ans = -0x3F3F, ans_start, ans_end;
        for (int i = 0; i < n; i++) {
            if (i and dp[i-1] + data[i] > data[i]) {
                dp[i] = dp[i-1] + data[i];
                end = i;
            } else {
                dp[i] = data[i];
                start = end = i;
            }

            if (dp[i] > ans) {
                ans = dp[i];
                ans_start = start;
                ans_end = end;
            }
        }

        printf("Case %d:\n", ++casen);
        printf("%d %d %d\n", ans, ans_start+1, ans_end+1);
        if (t)
            printf("\n");
    }
    
    return 0;
}