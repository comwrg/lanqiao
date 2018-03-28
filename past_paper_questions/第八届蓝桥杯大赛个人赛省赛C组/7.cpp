#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const long long tables[] = {1, 26, 676, 17576, 456976, 11881376, 308915776, 8031810176, 208827064576, };
const int tables_size = sizeof(tables) / sizeof(long long);

int main() {
    rdIn("data.txt");
    // 1-26, 26进制

    // 打表
//    long long sum = 1;
//    for (int i = 0; i < 10; i++) {
//        sum *= 26;
//        printf("%lld, ", sum);
//    }

    long long n;
    while (~scanf("%lld", &n)) {
        vector<long long> v;
        while (n) {
            v.push_back(n%26);
            n /= 26;
        }

        for (int i = 0; i < v.size(); i++) {
            if (v.at(i) == 0) {
                v.at(i) = 26;
                int j = i;
                while (++j < v.size()) {
                    if (v.at(j)) {
                        v.at(j)--;
                        break;
                    } else {
                        v.at(j) = 25;
                    }
                }
            }
        }

        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            printf("%c", 'A'-1+v.at(i));
        }
        printf("\n");
    }

    return 0;
}