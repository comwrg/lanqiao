/**
 * http://acm.hdu.edu.cn/showproblem.php?pid=1034
 */
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int n;
int candy[1024];
int half[1024];

bool end() {
    int base = candy[0];
    for (int i = 1; i < n; i++) {
        if (base != candy[i]) {
            return false;
        }
    }
    return true;
}

int handle() {
    int times = 0;
    while (!end()) {
        times++;
        for (int i = 0; i < n; i++) {
            half[i] = candy[i] / 2;
            candy[i] /= 2;
        }
        for (int i = 0; i < n; i++) {
            int left = i-1;
            if (i == 0) {
                left = n-1;
            }
            candy[i] += half[left];
            if (candy[i] % 2) {
                candy[i]++;
            }
//            cout << candy[i] << " ";
        }
//        cout << endl;
    }
    return times;
}

int main() {
    rdIn("data.txt");

    while (~scanf("%d", &n) and n) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &candy[i]);
        }
        int times = handle();
        printf("%d %d\n", times, candy[0]);
    }
  
    return 0;
}