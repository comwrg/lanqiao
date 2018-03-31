#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int INF = 0x3F3F3F3F;
int min_path[26][26];

int main() {
    rdIn("data.txt");

    // init min_path
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (i == j) {
                min_path[i][j] = 0;
            } else {
                min_path[i][j] = INF;
            }
        }
    }

    // input
    char chs[2][1000];
    scanf("%s%s", chs[0], chs[1]);

    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        char ch[2];
        for (char &c : ch) {
            do {
                c = getchar();
            } while (c < 'a' or c > 'z');
        }
        int &v = min_path[ch[0] - 'a'][ch[1] - 'a'];
        // consider case ch[0] == ch[1]
        v = min(v, 1);

    }

    // calc min path by Floyd-Warshall algorithm
    for (int k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                min_path[i][j] = min(min_path[i][j], min_path[i][k] + min_path[k][j]);
            }
        }
    }

    auto len = strlen(chs[0]);
    int ans = 0;
    for (int i = 0; i < len; ++i) {
        ans += min_path[chs[0][i] - 'a'][chs[1][i] - 'a'];
        if (ans >= INF) {
            ans = -1;
            break;
        }
    }
    cout << ans;

    return 0;
}