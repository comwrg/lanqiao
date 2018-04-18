#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

typedef pair<double, double> pdd;
vector<pdd> data;

double dis(int a, int b) {
    auto pa = data.at(a);
    auto pb = data.at(b);
    return sqrt(pow(pa.first-pb.first, 2) + pow(pa.second-pb.second, 2));
}

// [l ,r)
double divide(int l, int r) {
    if (r - l == 1) {
        return 0;
    }
    if (r - l == 2) {
        // two elements
        return dis(l, l+1);
    }
    if (r - l == 3) {
        // three elements
        double res[] = {
                dis(l+0, l+1),
                dis(l+0, l+2),
                dis(l+1, l+2),
        };
        return *min_element(res, res+3);
    }
    int mid = (l+r) / 2;
    double m = min(divide(l, mid), divide(mid, r));
    for (int i = mid; i < r; i++) {
        for (int j = mid-1; j >= l; j--) {
            if (data.at(i).first - data.at(j).first >= m)
                break;
            if (abs(data.at(i).second - data.at(j).second) >= m)
                continue;
            m = min(m, dis(i, j));
        }
    }
    return m;
}

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
        }
        if (minv) {
            data.clear();
            copy(s.begin(), s.end(), back_inserter(data));
            minv = divide(0, data.size());
        }
        printf("%.2lf", minv/2);
        printf("\n");
    }

    return 0;
}