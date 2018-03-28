#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int n = 29;
long long data[n+1][n+1];

int main() {
    rdIn("../C语言C组/4/data.txt");
    memset(data, 0, sizeof(data));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i+1; j++) {
            cin >> data[i][j];
            data[i][j] *= 1<<n;
        }
    }

    for (int i = 1; i < n+1; i++) {
        for (int j = 0; j < i+1; j++) {
            if (j == 0) {
                data[i][j] += data[i-1][0] / 2;
            } else if (j == i) {
                data[i][j] += data[i-1][j-1] / 2;
            } else {
                data[i][j] += (data[i-1][j-1]+data[i-1][j]) / 2;
            }
//            printf("%d, %d = %d\n", i, j, data[i][j]);
        }
    }
    sort(data[n], data[n]+n+1);
    for (int i = 0; i < n+1; i++) {
        cout << data[n][i] << endl;
    }

    return 0;
}