#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int NMAX = 1000000;
int data[NMAX];

int main() {
    rdIn("data.txt");

    int cnt = 0;
    for (int i = 2; i < NMAX; ++i) {
        if (data[i])
            continue;
        cnt++;
        for (int j = i; j < NMAX; j += i) {
            data[j] = cnt;
        }
    }

    int n;
    while (~scanf("%d", &n)) {
        printf("%d\n", data[n]);
    }
  
    return 0;
}