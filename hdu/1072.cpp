/**
 * http://acm.hdu.edu.cn/showproblem.php?pid=1072
 */
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

enum status {
    block = 0,
    empty = 1,
    start = 2,
    dest  = 3,
    reset = 4,
};

struct Info {
    int x, y;
    int step, time;
    Info(int x=0, int y=0, int time=6, int step=0) : x(x), y(y), time(time), step(step) {}
};

int h, w;
int maze[8][8];
int start_x, start_y;
int dest_x, dest_y;
queue<Info> que;

const int dir[4][2] = {
        {0, -1},
        {-1, 0},
        {1, 0},
        {0, 1},
};

bool crossed(int x, int y) {
    return (x < 0 or x >= h)
        or (y < 0 or y >= w);
}

void bfs() {
    while (!que.empty()) {
        auto item = que.front(); que.pop();
        if (crossed(item.x, item.y)) {
            continue;
        }
        if (maze[item.x][item.y] == block) {
            continue;
        }
        if (item.time <= 0) {
            //        ~~
            // important! not `<`
            continue;
        }
        if (maze[item.x][item.y] == dest) {
            printf("%d\n", item.step);
            return;
        }
        if (maze[item.x][item.y] == reset) {
            maze[item.x][item.y] = block;
            item.time = 6;
        }
        for (int i = 0; i < 4; i++) {
            int x = item.x + dir[i][0];
            int y = item.y + dir[i][1];
            que.push(Info(x, y, item.time-1, item.step+1));
        }
    }
    printf("-1\n");
}

int main() {
    rdIn("data.txt");

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &h, &w);
        for (int x = 0; x < h; x++) {
            for (int y = 0; y < w; y++) {
                scanf("%d", &maze[x][y]);
                if (maze[x][y] == start) {
                    start_x = x;
                    start_y = y;
                } else if (maze[x][y] == dest) {
                    dest_x = x;
                    dest_y = y;
                }
            }
        }
        while (!que.empty()) {
            que.pop();
        }
        que.push(Info(start_x, start_y));
        bfs();
    }
  
    return 0;
}