#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }

// 对于100%的数据，1 <= n, m , ai <= 1000
int n, m, a[1000], l, r, x, y, k;
int main() {
    rdIn("data.txt");

    while (cin >> n >> m) {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            int c;
            cin >> c;
            switch (c) {
                case 1:
                    cin >> l >> r >> x >> y;
                    l--; r--;
                    for (int j = l; j <= r; j++) {
                        if (a[j] == x) {
                            a[j] = y;
                        }
                    }
                    break;
                case 2:
                    cin >> l >> r >> k;
                    l--; r--; k--;
                    int b[1000];
                    int len = r - l + 1;
                    memcpy(b, a+l, len * sizeof(int));
                    sort(b, b + len);
                    cout << b[k] << endl;
                    break;
            }
        }
    }

    return 0;
}