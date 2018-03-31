#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

/** timeout
struct Node {
    int x, y, w;
};

int n, q;
vector<Node> data;

int main() {
    rdIn("data.txt");


    cin >> n;
    for (int i = 0; i < n; ++i) {
        Node n;
        cin >> n.x >> n.y >> n.w;
        data.push_back(n);
    }

    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        for (const Node &v : data) {
            if (v.x >= x1 and v.x <= x2
            and v.y >= y1 and v.y <= y2) {
                ans += v.w;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
 */

const int MAXN = 2001;
int n, q;
int data[MAXN][MAXN];

int get_data(int x, int y) {
    if (x < 0 or y < 0)
        return 0;
    return data[x][y];
}

int main() {
    rdIn("data.txt");

    memset(data, 0, sizeof(data));
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        data[x][y] += w;
    }

    // preprocess
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            data[i][j] += get_data(i-1, j) + get_data(i, j-1) - get_data(i-1, j-1);
        }
    }

    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = data[x2][y2] - get_data(x1-1, y2) - get_data(x2, y1-1) + get_data(x1-1, y1-1);
        cout << ans << endl;
    }

    return 0;
}