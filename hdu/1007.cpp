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


    vector<int> rmaybe;
    rmaybe.push_back(mid);
    auto pmid = data.at(mid);
    double miny = pmid.second;
    double maxy = pmid.second;
    for (int i = mid+1; i < r; i++) {
        auto pi = data.at(i);
        if (pi.first - pmid.first > m)
            break;
        miny = min(miny, pi.second);
        maxy = max(maxy, pi.second);
        rmaybe.push_back(i);
    }
    maxy += m;
    miny -= m;
    vector<int> lmaybe;
    for (int i = mid-1; i >= l; i--) {
        auto pi = data.at(i);
        if (pmid.first - pi.first > m)
            break;
        if (pi.second > maxy or pi.second < miny)
            continue;
        lmaybe.push_back(i);
    }

    for (int i : rmaybe) {
        for (int j : lmaybe) {
            auto pi = data.at(i);
            auto pj = data.at(j);
            if (pi.first - pj.first > m)
                break;
            if (abs(pi.second - pj.second) > m)
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