#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int NMAX = 1e5;
// k base, b lucky number
int k, b, n;
int data[NMAX];
int res[2*NMAX];

int main() {
    rdIn("data.txt");

    while (~scanf("%d %d %d", &k, &b, &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", data+i);
        }


        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int idx = j-i+1;
                memcpy(res, data+i, sizeof(int) * idx);
                reverse(res, res+idx);
                while (idx > 1) {
                    for (int i = 1; i < idx; ++i) {
                        res[0] += res[i];
                    }
                    idx = 0;
                    while (res[idx]) {
                        res[idx+1] = res[idx] / k;
                        res[idx] %= k;
                        ++idx;
                    }
                }
                if (res[0] == b)
                    ++ans;
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}