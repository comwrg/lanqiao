#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

bool valid(int n2, int n3) {
    char ch[2][1024];
    sprintf(ch[0], "%d", n2);
    sprintf(ch[1], "%d", n3);
    if (strlen(ch[0]) + strlen(ch[1]) != 10) {
        return false;
    }
    bool mark[10];
    memset(mark, 0, sizeof(mark));
    while (n2) {
        mark[n2%10] = true;
        n2 /= 10;
    }
    while (n3) {
        mark[n3%10] = true;
        n3 /= 10;
    }

    for (int i = 0; i < 10; i++) {
        if (!mark[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    for (int i = 0; i < 1000000; i++) {
        int n2 = pow(i, 2);
        int n3 = pow(i, 3);
        if (valid(n2, n3)) {
            cout << i << " " << n2 << " " << n3 << endl;
        }
    }

    return 0;
}

