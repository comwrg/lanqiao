#include <bits/stdc++.h>
using namespace std;

const string input[] = {
        "*26******",
        "***5*2**4",
        "***1****7",
        "*3**2*18*",
        "***3*9***",
        "*54*1**7*",
        "5****1***",
        "6**9*7***",
        "******75*",
};

int data[9][9];

void show() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool check(int x, int y) {
    int v = data[x][y];
    if (v < 0)
        return true;
    // row
    for (int i = 0; i < 9; i++) {
        if (i == y)
            continue;
        if (data[x][i] == v)
            return false;
    }
    // col
    for (int i = 0; i < 9; i++) {
        if (i == x)
            continue;
        if (data[i][y] == v)
            return false;
    }
    // table
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int tx = x/3*3 + i;
            int ty = y/3*3 + j;
            if (tx == x and ty == y)
                continue;
            if (v == data[tx][ty])
                return false;
        }
    }
    return true;
}

void handle(int x = 0, int y = 0) {
    if (x == 9) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (!check(i, j))
                    return;
            }
        }
        show();
        return;
    }
    if (y == 9) {
        handle(x+1, 0);
        return;
    }
    if (data[x][y] > 0) {
        handle(x, y+1);
        return;
    }
    for (int i = 1; i < 10; i++) {
        data[x][y] = i;
        if (check(x, y)) {
            handle(x, y+1);
        }
    }
    data[x][y] = -1;
}



int main() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (input[i][j] == '*') {
                data[i][j] = -1;
            } else {
                data[i][j] = input[i][j] - '0';
            }
        }
    }
    handle();
    return 0;
}