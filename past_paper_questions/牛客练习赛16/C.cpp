#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int NMAX = 1010;

int n;
int father[NMAX];
int o[NMAX][2];

int find(int i) {
    if (i == father[i])
        return i;
    return father[i] = find(father[i]);
}

void merge(int a, int b) {
    father[find(a)] = find(b);
}

int main() {
    rdIn("data.txt");

    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            int &x = o[i][0], &y = o[i][1];
            scanf("%d %d", &x, &y);
            father[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                int ix = o[i][0], iy = o[i][1];
                int jx = o[j][0], jy = o[j][1];
                if (ix == jx or iy == jy) {
                    merge(i, j);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (father[i] == i)
                ++ans;
        }
        printf("%d\n", ans-1);
    }


    return 0;
}