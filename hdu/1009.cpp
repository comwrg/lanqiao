#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

struct node {
    double p;
    int j, f;
    node (int j, int f) : j(j), f(f) {
        p = 1.0 * j / f;
    }
};

int main() {
    rdIn("data.txt");

    double m, n;
    while (~scanf("%lf %lf", &m, &n) and m > -1) {
        vector<node> data;
        for (int i = 0; i < n; ++i) {
            int j, f;
            scanf("%d %d", &j, &f);
            data.push_back(node(j, f));
        }
        sort(data.begin(), data.end(), [](node &a, node &b) -> int {
            return a.p > b.p;
        });

        double ans = 0;
        for (node nd : data) {
            if (m >= nd.f) {
                m -= nd.f;
                ans += nd.j;
            } else {
                ans += m / nd.f * nd. j;
                break;
            }
        }
        printf("%.3f\n", ans);
    }
    
    return 0;
}