#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }


//int xiang, rui, sheng, hui, san,  yang, xian, qi;
//    0      1    2      3    4     5     6     7
int data[8];
bool mark[10];
int res[5];
void handle(const int index = 0) {
    if (index == 8) {
        res[4] = data[3] + data[1];
        res[3] = data[2] + data[6];
        res[2] = data[1] + data[5];
        res[1] = data[0] + data[4];
        res[0] = 0;
        for (int i = 4; i > 0; i--) {
            res[i-1] += res[i] / 10;
            res[i] %= 10;
        }
        if (res[0] == data[4] and
            res[1] == data[5] and
            res[2] == data[2] and
            res[3] == data[1] and
            res[4] == data[7] and
            data[0] and data[4]) {
            cout << data[4] << " "
                 << data[5] << " "
                 << data[6] << " "
                 << data[1] << endl;
        }
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (mark[i]) {
            continue;
        }
        mark[i] = true;
        data[index] = i;
        handle(index + 1);
        mark[i] = false;
    }
}


int main() {
    memset(mark, 0, sizeof(mark));
    handle();

    return 0;
}