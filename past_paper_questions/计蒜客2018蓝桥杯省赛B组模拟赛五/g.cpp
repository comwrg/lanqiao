#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int n;
stack<int> data;

int main() {
    rdIn("data.txt");

    while (~scanf("%d", &n)) {
        while (!data.empty())
            data.pop();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int m;
            scanf("%d", &m);

            while (1) {
                if (data.empty()) {
                    data.push(m);
                    break;
                }
                if (m - data.top() == 1) {
                    cnt++;
                    break;
                } else if (data.top() - m == 1) {
                    cnt++;
                    data.pop();
                } else {
                    data.push(m);
                    break;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}