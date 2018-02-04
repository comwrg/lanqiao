#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }

int main() {
    rdIn("data.txt");

    int n;
    while (~scanf("%d", &n)) {
        int res[100000];
        memset(res, -1, sizeof(res));
        res[0] = 1;
        int cur;
        for (int i = 2; i <= n; i++) {
            div_t d; memset(&d, 0, sizeof(d));
            cur = 0;
            for (; res[cur] != -1; cur++) {
                res[cur] *= i;
                res[cur] += d.quot;
                d = div(res[cur], 10);
                res[cur] = d.rem;
            }
            while (d.quot) {
                res[cur] = d.quot;
                d = div(res[cur], 10);
                res[cur] = d.rem;
                cur++;
            }
        }

        for (int i = cur-1; i >= 0; i--) {
            printf("%d", res[i]);
        }

        printf("\n");
    }

    return 0;
}