#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int NMAX = 1e5 + 10;
// k base, b lucky number
int k, b, n;
int data[NMAX];
int sum[NMAX];

int main() {
    rdIn("data.txt");

    while (~scanf("%d %d %d", &k, &b, &n)) {
        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", data+i);
            data[i] = 1 + (data[i]-1) % (k-1);
            sum[i] = sum[i-1] + data[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                int s = sum[i] - sum[j];
                int dr = 1 + (s-1) % (k-1);
                if (dr == b) {
                    ++ans;
                }
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}