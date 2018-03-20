#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }
typedef long long LL;
const long long MOD = 10e9 + 7;
int n, m;
int mux[36][2];
short data[10000000000];
int sum;

bool ismux(int a, int b) {
    for (int i = 0; i < m; i++) {
        if ((mux[i][0] == a and mux[i][1] == b)
         or (mux[i][0] == b and mux[i][0] == a)) {
            return true;
        }
    }
    return false;
}

void handle(const int index = 0) {
    if (index == n) {
        sum++;
        return;
    }
    for (short i = 1; i <= 6; i++) {
        if ((index == 0) or (index > 0 and !ismux(i, data[index-1]))) {
            data[index] = i;
            handle(index + 1);
        }
    }
}

int main() {
    rdIn("data.txt");

    while (~scanf("%d %d", &n, &m)) {
        sum = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &mux[i][0], &mux[i][1]);
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