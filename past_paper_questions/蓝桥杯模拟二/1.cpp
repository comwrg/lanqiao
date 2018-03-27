#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int data[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int data1[3][3];
int data2[3][3];
int ans[3][3];

// ans = data1 * data2
void calc(int x, int y) {
    for (int i = 0; i < 3; i++) {
        ans[x][y] += data1[x][i] * data2[i][y];
    }
}

void mult() {
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            calc(i, j);
        }
    }
}

int main() {
    memcpy(data1, data, sizeof(data));
    memcpy(data2, data, sizeof(data));
    for (int i = 0; i < 5; i++) {
        mult();
        memcpy(data1, ans, sizeof(data));
    }

    for (int i = 0; i < 3; i++) {
        printf("%d", ans[i][0]);
        for (int j = 1; j < 3; j++) {
            printf(" %d", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}