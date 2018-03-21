#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }
typedef long long LL;
const long long MOD = 10e9 + 7;
int n, m;
bool mux[7][7];
short data[10000000000];
int sum;

void handle(const int index = 0) {
    if (index == n) {
        sum++;
        return;
    }
    for (short i = 1; i <= 6; i++) {
        if ((index == 0) or (index > 0 and mux[data[index-1]][i] == 0)) {
            data[index] = i;
            handle(index + 1);
        }
    }
}

int main() {
    rdIn("data.txt");

    while (~scanf("%d %d", &n, &m)) {
        memset(mux, 0, sizeof(mux));
        sum = 0;
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            if (b + 3 <= 6) {
                mux[a][b+3] = 1;
            } else {
                mux[a][b-3] = 1;
            }
            if (a + 3 <= 6) {
                mux[b][a+3] = 1;
            } else {
                mux[b][a-3] = 1;
            }
        }
        handle();
        for (int i = 0; i < n; i++) {
            sum *= 4;
            sum %= MOD;
        }
        cout << sum << endl;
    }
  
  
    return 0;
}
