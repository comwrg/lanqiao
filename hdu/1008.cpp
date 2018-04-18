#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int main() {
    rdIn("data.txt");

    int n;
    while (~scanf("%d", &n) and n) {
        int total = 0;
        int now_floor = 0;
        for (int i = 0; i < n; ++i) {
            int dst;
            scanf("%d", &dst);
            total += 5;
            if (now_floor > dst) {
                total += (now_floor - dst) * 4;
            } else {
                total += (dst - now_floor) * 6;
            }
            now_floor = dst;
        }
        printf("%d\n", total);
    }
    
    return 0;
}