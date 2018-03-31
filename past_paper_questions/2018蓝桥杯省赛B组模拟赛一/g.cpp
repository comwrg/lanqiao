#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int n;
double a[2];
double c[1001];

int main() {
    rdIn("data.txt");

    cin >> n;
    cin >> a[0] >> a[1];
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    double p[4] = {1, 0.5, 0.5, -c[n]};
    for (int i = n-1; i > 0; i--) {
        p[0] -= p[1] / 2;
        p[1] = 0.5;
        p[2] /= 2;
        p[3] = p[3] / 2 - c[i];

        for (int j = 3; j > 0; j--) {
            p[j] *= 1 / p[0];
        }
        p[0] = 1;
    }

//    for (double i : p) {
//        cout << i << " ";
//    }
//    cout << endl;
    double ans = p[1]*a[0] + p[2]*a[1] + p[3];
    printf("%.2lf", ans);

    return 0;
}