#include <bits/stdc++.h>

using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

int data[][4] = {
        {1, 4, 2, 5},
        {2, 1, 2, 1},
        {3, 1, 3, 2},
        {2, 5, 3, 4},
};

int dir[][2] = {
        {1, 0}, {0, 1},
        {-1, 0},{0, -1},
};

bool crossed(int x, int y) {
    return (x < 0 or x >= 4) or (y < 0 or y >= 4);
}

bool isborder(int x, int y) {
    if (data[x][y] == -1) {
        return false;
    }
    for (auto &i : dir) {
        int nx = x + i[0];
        int ny = y + i[1];
        if (crossed(nx, ny) or data[nx][ny] == -1) {
            return true;
        }
    }
    return false;
}

vector<Point> getborder() {
    vector<Point> border;
    border.clear();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (isborder(i, j)) {
                border.emplace_back(i, j);
            }
        }
    }
    return border;
}

struct Node {
    int scores, times;
    string step;
    Node(int scores = 0, int times = 1, string step = "") : scores(scores), times(times), step(move(step)) {}
};

Node dfs(Node n) {
    Node mx = n;
    auto border = getborder();
    for (auto lt1 = border.begin(); lt1 != border.end(); lt1++) {
        auto p1 = *lt1;
        for (auto lt2 = lt1+1; lt2 != border.end(); lt2++) {
            auto p2 = *lt2;
            int p1v = data[p1.x][p1.y];
            int p2v = data[p2.x][p2.y];
            if (p1v != p2v) {
                continue;
            }
            data[p1.x][p1.y] = -1;
            data[p2.x][p2.y] = -1;
            char ch[100];
            snprintf(ch, sizeof(ch), "[%d(%d, %d), %d(%d, %d)], ", p1v, p1.x, p1.y, p2v, p2.x, p2.y);
            string step = ch;
            Node r = dfs(Node(n.scores + n.times*p1v, n.times+1, n.step + step));
//            printf("%d %d\n", scores, times);
            if (r.scores > mx.scores) {
                mx = r;
            }
            // recover
            data[p1.x][p1.y] = p1v;
            data[p2.x][p2.y] = p2v;
        }
    }
    return mx;
}

int main() {
    rdIn("data.txt");

    auto n = dfs(Node());
    cout << n.scores << endl;
    cout << n.step << endl;


    return 0;
}