#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int NMAX = 1000;
int n, m;
int father[NMAX];

int find(int i) {
    if (i == father[i])
        return i;
    return find(father[i]);
}

void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    if (x != y)
        father[x] = y;
}


int main() {
    rdIn("data.txt");

    while (~scanf("%d", &n) and n) {
        for (int i = 1; i <= n; ++i) {
            father[i] = i;
        }

        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            merge(a, b);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (father[i] == i)
                ans++;
        }
        printf("%d\n", ans-1);
    }

  
    return 0;
}