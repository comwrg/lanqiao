#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int NMAX = 100000;
char chs[NMAX];

int main() {
    rdIn("data.txt");

    while (~scanf("%s", chs)) {
        int len_chs = strlen(chs);
        int last = 0;
        for (int i = 'z'; i >= 'a'; --i) {
            for (int j = last; j < len_chs; ++j) {
                if (chs[j] == i) {
                    printf("%c", i);
                    last = j;
                }
            }
        }
        printf("\n");
    }
    
    return 0;
}
