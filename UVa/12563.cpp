/**
 * Jin Ge Jin Qu [h]ao, Rujia Liu's Present 6, UVa 12563
 *
 * Sample Input
 * 2 3 100 60 70 80 3 100 30 69 70
 *
 * Sample Outpu
 * Case 1: 2 758
 * Case 2: 3 777
 */
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
const int INF = 0x3F3F3F3F;

int n; // n <= 50
int t; // t <= 1e9
int data[50]; // data[i] <= 3*60 = 180
const int T_JQ = 11 * 60 + 18;
const int MAX_T = 180 * 50 + T_JQ;
struct node {
    int left_time;
    int songs;
    node(int left_time = INF, int songs = 0) : left_time(left_time), songs(songs) {};
    bool operator <(const node &rhs) const {
        return this->left_time < rhs.left_time;
    }
};

node foo(node nd, int songs) {
    if (nd.left_time < 1) {
        return INF;
    }
    if (songs == n) {
        return nd;
    }
    auto a = foo(nd.left_time, songs+1);
    auto b = foo(nd.left_time - data[songs], songs+1);
    b.songs++;
    return min(a, b);
}

int main() {
    rdIn("data.txt");

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        memset(data, 0, sizeof(data));

        cin >> n >> t;
        for (int j = 0; j < n; j++) {
            cin >> data[j];
        }

        auto n = foo(t, 0);
        cout << n.songs + 1 << " " << t - n.left_time + T_JQ << endl;

    }

    return 0;
}