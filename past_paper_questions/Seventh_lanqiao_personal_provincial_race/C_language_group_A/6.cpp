/**
 * 寒假作业
 *
 * 现在小学的数学题目也不是4那么好玩的。
 * 看看这个寒假作业：
 *
 * □ + □ = □
 * □ - □ = □
 * □ × □ = □
 * □ ÷ □ = □
 *
 * (如果显示不出来，可以参见【图1.jpg】)
 * {
 * 每个方块代表1~13中的某一个数字，但不能重复。
 * 比如：
 * 6  + 7 = 13
 * 9  - 8 = 1
 * 3  * 4 = 12
 * 10 / 2 = 5
 *
 * 以及：
 * 7  + 6 = 13
 * 9  - 8 = 1
 * 3  * 4 = 12
 * 10 / 2 = 5
 *
 * 就算两种解法。（加法，乘法交换律后算不同的方案）
 *
 * 你一共找到了多少种方案？
 *
 *
 * 请填写表示方案数目的整数。
 * 注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
 */

#include <iostream>

#define MIN 1
#define MAX 13

#define ROW    4
#define COLUMN 3

#define MARK_UNUSED 0
#define MARK_USED   1

using namespace std;

void n2xy(int n, int& x, int& y) {
    x = n / COLUMN;
    y = n % COLUMN;
}

int calc(const int arr[ROW][COLUMN], int x) {
    switch (x) {
        case 0:
            return arr[x][0] + arr[x][1];
        case 1:
            return arr[x][0] - arr[x][1];
        case 2:
            return arr[x][0] * arr[x][1];
        case 3:
            return arr[x][0] / arr[x][1];
    }
}

void show(const int arr[ROW][COLUMN]) {
    cout << arr[0][0] << " + " << arr[0][1] << " = " << arr[0][2] << endl;
    cout << arr[1][0] << " - " << arr[1][1] << " = " << arr[1][2] << endl;
    cout << arr[2][0] << " * " << arr[2][1] << " = " << arr[2][2] << endl;
    cout << arr[3][0] << " / " << arr[3][1] << " = " << arr[3][2] << endl;
    cout << endl;
}

void foo(int arr[ROW][COLUMN], int pos, int mark[MAX+1], int& sum) {
    if (pos >= ROW*COLUMN) {
        // show
        cout << ++sum << endl;
        show(arr);
        return;
    }
    for (int i = MIN; i <= MAX; i++) {
        if (mark[i] != MARK_UNUSED) {
            continue;
        }
        int x, y;
        n2xy(pos, x, y);
        // judgment whether can be divided
        if ((x == 3 && y == 1)
            && arr[x][0] % i != 0) {
            continue;
        }
        arr[x][y] = i;
        mark[i] = MARK_USED;
        int d;
        if (y == 1) {
            d = calc(arr, x);
            if ((d < MIN || d > MAX)
                || mark[d] != MARK_UNUSED) {
                // resume! important! i forgot and it's so hard to debug the code
                mark[i] = MARK_UNUSED;
                continue;
            }
            arr[x][2] = d;
            mark[d] = MARK_USED;
            foo(arr, pos+2, mark, sum);
        } else {
            foo(arr, pos+1, mark, sum);
        }
        // resume
        if (y == 1) {
            mark[d] = MARK_UNUSED;
        }
        mark[i] = MARK_UNUSED;
    }
}

int main() {
    int arr[ROW][COLUMN];
    int mark[MAX+1];
    for (int& i : mark)
        i = MARK_UNUSED;
    int sum = 0;
    foo(arr, 0, mark, sum);
    getchar();

    return 0;
}

