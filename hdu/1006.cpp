#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int main() {
    rdIn("data.txt");

    int d;
    while (~scanf("%d", &d) and ~d) {
        int total = 0, valid = 0;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                for (int s = 0; s < 60; s++) {
                    double h_degrees = (h*60*60 + m*60 + s) * (360.0 / 12 / 60 / 60);
                    double m_degrees = (m*60 + s) * (360.0 / 60 / 60);
                    double s_degrees = s * (360.0 / 60);

                    double arr[3] = {
                            abs(h_degrees - m_degrees),
                            abs(h_degrees - s_degrees),
                            abs(m_degrees - s_degrees),
                    };
                    for (double &i : arr) {
                        if (i > 180) {
                            i = 360 - i;
                        }
                    }
                    sort(arr, arr+3);
                    if (arr[0] >= d and arr[1] >= d and arr[2] >= d) {
                        valid++;
                        printf("(%d %d %d), %lf, %lf, %lf ", h, m, s, arr[0], arr[1], arr[2]);
                        printf("(%lf, %lf, %lf", h_degrees, m_degrees, s_degrees);
                        printf("\n");
                    }
                    total++;
                }
            }
        }
        printf("%.3lf\n", 100.0 * valid / total);
    }


    return 0;
}