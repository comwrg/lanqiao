#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int n, q, p, x, y;
int number = 0;
int chess[4][4] = {
        {11, 10, 9, 8},
        {12, 0,  0, 7},
        {1,  0,  0, 6},
        {2,  3,  4, 5},
};

int data[4][4];

void del(int dstX, int dstY) {
    debug("del %d, %d\n", dstX, dstY);
    data[dstX][dstY] = 0;
}
enum Color {
        black,
        white,
        no
};

Color color(int dstX, int dstY) {
    int v = data[dstX][dstY];
    if (v == 0) {
        return no;
    }else if (1 <= v and v <= 6) {
        return black;
    } else {
        return white;
    }
}

void judge() {
    // row
    if (data[x][0] == 0 and color(x, y) == color(x, 2)
     or data[x][3] == 0 and color(x, y) == color(x, 1)) {
        int nBlack = 0, nWhite = 0;
        int blackX, blackY;
        int whiteX, whiteY;
        for (int i = 0; i < 4; i++) {
            Color c = color(x, i);
            if (c == black) {
                nBlack++;
                blackX = x; blackY = i;
            } else if (c == white) {
                nWhite++;
                whiteX = x; whiteY = i;
            }
        }
        if (nBlack == 1 and nWhite == 2 and color(x, y) == white) {
            del(blackX, blackY);
        }
        if (nBlack == 2 and nWhite == 1 and color(x, y) == black) {
            del(whiteX, whiteY);
        }
    }

    // column
    if (data[0][y] == 0 and color(x, y) == color(2, y)
     or data[3][y] == 0 and color(x, y) == color(1, y)) {
        int nBlack = 0, nWhite = 0;
        int blackX, blackY;
        int whiteX, whiteY;
        for (int i = 0; i < 4; i++) {
            Color c = color(i, y);
            if (c == black) {
                nBlack++;
                blackX = i; blackY = y;
            } else if (c == white) {
                nWhite++;
                whiteX = i; whiteY = y;
            }
        }
        if (nBlack == 1 and nWhite == 2 and color(x, y) == white) {
            del(blackX, blackY);
        }
        if (nBlack == 2 and nWhite == 1 and color(x, y) == black) {
            del(whiteX, whiteY);
        }
    }
}

void find(int id, int &x, int &y) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (id == data[i][j]) {
                x = i;
                y = j;
                return;
            }
        }
    }
}

void print() {
    printf("#Case %d:\n", ++number);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%3d", data[i][j]);
        }
        printf("\n");
    }
}

void move(int destX, int destY) {
    debug("move %d, %d to %d, %d\n", x, y, destX, destY);
    data[destX][destY] = data[x][y];
    data[x][y] = 0;
}

int main() {
    rdIn("data.txt");

    while (~scanf("%d", &n)) {
        memcpy(data, chess, sizeof(chess));
        for (int _ = 0; _ < n; _++) {
            scanf("%d %d", &q, &p);
            find(q, x, y);
            switch (p) {
                case 1:
                    // 上
                    move(x-1, y);
                    x--;
                break;
                case 2:
                    // 下
                    move(x+1, y);
                    x++;
                break;
                case 3:
                    // 左
                    move(x, y-1);
                    y--;
                break;
                case 4:
                    // 右
                    move(x, y+1);
                    y++;
                break;
            }
            judge();
        }
        print();
    }

    return 0;
}

/**
#Case 1:
  0  0  9  8
  0 10  7  0
  2 12  4  0
  0  0  0  5
 */