/**
 * http://acm.hdu.edu.cn/showproblem.php?pid=1312
 */
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

enum Tile {
    black,
    red,
};

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
};

const int dir[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
};

int w, h;
int data[20][20];
bool arrived[20][20];
queue<Point> que;
int times;

bool crossed(Point p) {
    return p.x < 0 or p.x >= h
        or p.y < 0 or p.y >= w;
}


void bfs() {
    while (!que.empty()) {
        times++;
        Point p = que.front();
        debug("(%d, %d) -> ", p.x, p.y);
        arrived[p.x][p.y] = 1;
        for (int i = 0; i < 4; i++) {
            Point next(p.x+dir[i][0], p.y+dir[i][1]);
            if (crossed(next)) {
                continue;
            }
            if (data[next.x][next.y] != black) {
                continue;
            }
            if (arrived[next.x][next.y]) {
                continue;
            }
            debug("(%d, %d) ", next.x, next.y);
            que.push(next);
            arrived[next.x][next.y] = 1;
        }
        debug("\n");
        que.pop();
    }
}

int main() {
    rdIn("data.txt");

    while (~scanf("%d %d\n", &w, &h)) {
        if (w == 0 and h == 0) {
            break;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char c = getchar();
                switch (c) {
                    case '.':
                        data[i][j] = black;
                    break;
                    case '#':
                        data[i][j] = red;
                    break;
                    case '@':
                        data[i][j] = black;
                        que.push(Point(i, j));
                    break;
                }
            }
            getchar();
        }
        memset(arrived, 0, sizeof(arrived));
        times = 0;
        bfs();
        printf("%d\n", times);
    }

    return 0;
}