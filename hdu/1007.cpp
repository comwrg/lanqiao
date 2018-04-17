#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

typedef pair<double, double> pdd;

int main() {
    rdIn("data.txt");
    int n;
    while (~scanf("%d", &n) and n) {
        set<pair<double, double>> s;
        double minv = 0x3f3f3f3f;
        while (n--) {
            double x, y;
            scanf("%lf %lf", &x, &y);
            for (auto o : s) {
                minv = min(minv, pow(x-o.first, 2) + pow(y-o.second, 2));
            }
            s.insert(make_pair(x, y));
        }
        printf("%.2lf", sqrt(minv)/2);
        printf("\n");
    }

    return 0;
}