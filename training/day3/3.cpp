/**
 * http://acm.hdu.edu.cn/showproblem.php?pid=1010
 */
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int height, width, time_open;
int maze[10][10];
bool record[10][10];
int door_x, door_y;
int start_x, start_y;

enum mark {
    block,
    start,
    door,
    empty,
};

bool handle(const int x, const int y, const int time = 0) {
    if (time == time_open) {
        return (x == door_x and y == door_y);
    }
//    printf("(%d, %d)\n", x, y);

    for (int i = 0; i < 4; i++) {
        int next_x = x,
            next_y = y;
        switch (i) {
            case 0:
                next_x++;
            break;
            case 1:
                next_x--;
            break;
            case 2:
                next_y++;
            break;
            case 3:
                next_y--;
            break;
        }
        if (next_x < 0 || next_x >= height
         || next_y < 0 || next_y >= width) {
            continue;
        }
        if (record[next_x][next_y]) {
            continue;
        }
        if (maze[next_x][next_y] != empty and maze[next_x][next_y] != door) {
            continue;
        }
        record[next_x][next_y] = true;
        bool r = handle(next_x, next_y, time+1);
        record[next_x][next_y] = false;
        if (r) {
            return true;
        }
    }

    return false;
}

int main() {
    rdIn("data.txt");

    while (~scanf("%d %d %d\n", &height, &width, &time_open)) {
        if (height == 0 and width == 0 and time_open == 0) {
            break;
        }
        for (int x = 0; x < height; x++) {
            for (int y = 0; y < width; y++) {
                char c = getchar();
                if (c == 'X') {
                    maze[x][y] = block;
                } else if (c == 'S') {
                    maze[x][y] = start;
                    start_x = x;
                    start_y = y;
                } else if (c == 'D') {
                    maze[x][y] = door;
                    door_x = x;
                    door_y = y;
                } else if (c == '.') {
                    maze[x][y] = empty;
                }
            }
            getchar();
        }
        memset(record, 0, sizeof(record));
        bool r;
        int shortest = abs(door_x-start_x) + abs(door_y-start_y);
        int dis = time_open - shortest;
        if (dis < 0 or dis & 1) {
            r = false;
        } else {
            r = handle(start_x, start_y);
        }
        if (r) {
            printf("YES");
        } else {
            printf("NO");
        }
        printf("\n");
    }

  
    return 0;
}