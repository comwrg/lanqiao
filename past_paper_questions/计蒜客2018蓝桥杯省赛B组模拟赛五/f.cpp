#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }
const int n = 10;
const char maze[][n+1] = {
    ".......9..",
    "...X..0...",
    ".X..8..X..",
    ".7...X..6.",
    ".X..5.X...",
    "..X....X..",
    ".....X..3.",
    ".X.X..1...",
    ".4....XX..",
    "..X..X2...",
};

enum Status {
    empty = '.',
    block = 'X',

};

struct Node {
    int x, y, step, find;
    Node(int x = 0, int y = 0, int step = 0, int find = 0) : x(x), y(y), step(step), find(find) {}
};

const int dir[][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

bool crossed(int x, int y) {
    return x < 0 or x >= n or y < 0 or y >= n;
}

queue<Node> que;
bool status[n][n][1<<11];
Node bfs() {
    while (!que.empty()) {
        auto item = que.front(); que.pop();
        if (item.x == 0 and item.y == 0 and item.find == 0b1111111111) {
            return item;
        }
        for (auto &i : dir) {
            Node next;
            next.x = item.x + i[0];
            next.y = item.y + i[1];
            next.step = item.step + 1;
            next.find = item.find;
            if (crossed(next.x, next.y))
                continue;
            char v = maze[next.x][next.y];
            if (v == block)
                continue;
            if (v != empty) {
                next.find |= 1 << (v - '0');
            }
            if (status[next.x][next.y][next.find])
                continue;
            status[next.x][next.y][next.find] = 1;
            que.push(next);
        }
    }
}

int main() {
    memset(status, 0, sizeof(status));
    que.push(Node());
    cout << bfs().step;

    return 0;
}