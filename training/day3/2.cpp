/**
 * http://acm.hdu.edu.cn/showproblem.php?pid=1015
 */
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }
typedef long long LL;

LL target;
char tables[26];
size_t tables_len;
int mark[26];
int data[5];

bool handle(const int index = 0) {
    if (index == 5) {
        LL r = data[0] - pow(data[1], 2) + pow(data[2], 3) - pow(data[3], 4) + pow(data[4], 5);
        if (r == target) {
            return true;
        }
        return false;
    }
    for (int i = tables_len-1; i >= 0; i--) {
        if (mark[i]) {
            continue;
        }
        mark[i] = true;
        data[index] = tables[i];
        bool r = handle(index + 1);
        mark[i] = false;
        if (r) {
            return true;
        }
    }
    return false;
}

int main() {
    rdIn("data.txt");

    while (~scanf("%lld ", &target)) {
        memset(mark, 0, sizeof(mark));
        gets(tables);
        if (target == 0 and strcmp(tables, "END") == 0) {
            break;
        }
        tables_len = strlen(tables);
        for (int i = 0; i < tables_len; i++) {
            tables[i] -= ('A' - 1);
        }
        sort(tables, tables+tables_len);
        bool r = handle();
        if (r) {
            for (int i = 0; i < 5; i++) {
                printf("%c", data[i] + ('A' - 1));
            }
        } else {
            printf("no solution");
        }
        printf("\n");
    }

    return 0;
}