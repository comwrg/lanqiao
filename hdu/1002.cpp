#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int main() {
    rdIn("data.txt");
    int n;
    scanf("%d", &n);
    int casen = 0;
    while (n--) {
        char chs[3][1000];
        int chs_len[3];
        memset(chs, 0, sizeof(chs));
        scanf("%s %s", chs[0], chs[1]);
        for (int i = 0; i < 2; i++) {
            chs_len[i] = strlen(chs[i]);
            reverse(chs[i], chs[i]+chs_len[i]);
            for (int j = 0; j < chs_len[i]; j++) {
                chs[i][j] -= '0';
            }
        }

        for (int i = 0; i < max(chs_len[0], chs_len[1]); i++) {
            chs[2][i] += chs[0][i] + chs[1][i];
        }

        for (int i = 0; i < 1000; i++) {
            chs[2][i+1] += chs[2][i] / 10;
            chs[2][i] %= 10;
        }
        for (chs_len[2] = 1000; chs_len[2] > 0 and chs[2][chs_len[2]-1] == 0; chs_len[2]--);
        for (int i = 0; i < 3; i++) {
            reverse(chs[i], chs[i]+chs_len[i]);
            for (int j = 0; j < chs_len[i]; j++) {
                chs[i][j] += '0';
            }
        }

        printf("Case %d:\n", ++casen);
        printf("%s + %s = %s\n", chs[0], chs[1], chs[2]);
        if (n > 0)
            printf("\n");
        //  ~~~~~~~~~~~~
        // if not this will be `Presentation Error`
        // first, i wrote `\n\n`, not AC.. nothing to say.
    }

    return 0;
}