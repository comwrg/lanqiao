#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int leap(int y) {
    return ((y % 100 == 0 and y % 4 == 0) or (y % 100 != 0 and y % 400 == 0));
}

const int months[] = {0, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    rdIn("data.txt");

    int y, m, d;
    while (~scanf("%d-%d-%d", &y, &m, &d)) {
        // 2017-02-23
        int ld = -(31 + 23) + d;
        for (int i = 2017; i < y; i++) {
            ld += 366;
            if (leap(i)) {
                ld--;
            }
        }
        for (int i = 1; i < m; i++) {
            ld += months[i];
            if (i == 2 and leap(y)) {
                ld--;
            }
        }
        cout << ld << endl;
    }

  
    return 0;
}