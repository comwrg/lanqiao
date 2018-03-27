#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int main() {
    rdIn("data.txt");

    const int maxn = 1e5+10;
    int data[maxn], diff[maxn];
    int pre[maxn], suf[maxn];

    int n;
    while (~scanf("%d", &n)) {
        int diff_size = n - 1;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            int m;
            scanf("%d", &m);
            data[i] = m;
        }
        if (diff_size < 3) {
            printf("0\n");
            continue;
        }
        sort(data, data+n);
        for (int i = 1; i < n; i++) {
            int m = data[i] - data[i-1];
            diff[i-1] = m;
            sum += m;
        }
        // prefix gcd, pre[i] mean gcd[0, i]
        pre[0] = diff[0];
        for (int i = 1; i < diff_size; i++) {
            pre[i] = gcd(diff[i], pre[i-1]);
        }
        // suffix gcd, suf[i] mean gcd[i, diff_size-1]
        suf[diff_size-1] = diff[diff_size-1];
        for (int i = diff_size-2; i >= 0; i--) {
            suf[i] = gcd(diff[i], suf[i+1]);
        }

        long long ans = 0x3F3F3F3F;
        for (int i = 0; i < diff_size; i++) {
            int g;
            if (i == 0) {
                g = suf[1];
            } else if (i == diff_size-1) {
                g = pre[i-1];
            } else {
                g = gcd(pre[i-1], suf[i+1]);
            }
            auto r = sum - diff[i];
            r /= g;
            r -= diff_size-1;
            ans = min(ans, r);
        }
        printf("%lld\n", ans);
    }

    return 0;
}