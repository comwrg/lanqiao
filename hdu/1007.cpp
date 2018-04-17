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
            auto p = make_pair(x, y);
            auto it = s.find(p);
            if (it != s.end()) {
                minv = 0;
                break;
            }
            s.insert(p);
            auto f = s.find(p);
            it = f;
            while (it++ != --s.end() and it->first - x < minv and abs(it->second - y) < minv) {
                minv = min(minv, sqrt(pow(x-it->first, 2) + pow(y-it->second, 2)));
            }
            it = f;
            while (it-- != s.begin() and x - it->first < minv) {
                if (abs(it->second - y) >= minv)
                    continue;
                minv = min(minv, sqrt(pow(x-it->first, 2) + pow(y-it->second, 2)));
            }

        }
        printf("%.2lf", minv/2);
        printf("\n");
    }

    return 0;
}