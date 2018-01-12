/**
 * 方格填数
 *
 * 如下的10个格子
 *    +--+--+--+
 *    |  |  |  |
 * +--+--+--+--+
 * |  |  |  |  |
 * +--+--+--+--+
 * |  |  |  |
 * +--+--+--+
 *
 * （如果显示有问题，也可以参看【图1.jpg】）
 *
 * 填入0~9的数字。要求：连续的两个数字不能相邻。
 * （左右、上下、对角都算相邻）
 *
 * 一共有多少种可能的填数方案？
 *
 * 请填写表示方案数目的整数。
 * 注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
 */
#include <iostream>

#define ROW    3
#define COLUMN 4



// chessboard status
namespace chess {
    enum CHESS_STATUS {
        BAN      = -0x1,
        NOT_USED = -0x2,
    };
}

void show(const int chess[ROW][COLUMN], int sum) {
    std::cout << "[" << sum << "]" << std::endl;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            switch (chess[i][j]) {
                case chess::BAN:
                    std::cout << "  ";
                    break;
                case chess::NOT_USED:
                    std::cout << "| ";
                    break;
                default:
                    std::cout << chess[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool isValid(const int chess[ROW][COLUMN], int n, int x, int y) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            if (chess[i][j] == chess::BAN || chess[i][j] == chess::NOT_USED)
                continue;
            if (abs(x - i) < 2 && abs(y - j) < 2
                && abs(n - chess[i][j]) < 2) {
                return false;
            }
        }
    }
    return true;
}

void foo(int chess[ROW][COLUMN], int n, int& sum) {
    if (n == 10) {
        show(chess, ++sum);
        return;
    }

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            if (chess[i][j] != chess::NOT_USED)
                continue;
            if (!isValid(chess, n, i, j))
                continue;
            chess[i][j] = n;
            foo(chess, n + 1, sum);
            chess[i][j] = chess::NOT_USED;
        }
    }
}

int main() {
    int chess[ROW][COLUMN];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            chess[i][j] = chess::NOT_USED;
        }
    }

    chess[0][0] = chess::BAN;
    chess[2][3] = chess::BAN;
    int sum = 0;
    foo(chess, 0, sum);
    getchar();

    return 0;
}