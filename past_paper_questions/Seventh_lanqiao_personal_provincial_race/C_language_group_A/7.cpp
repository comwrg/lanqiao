/**
 *
 * 剪邮票
 *
 * 如【图1.jpg】, 有12张连在一起的12生肖的邮票。
 * 【图1.jpg】
 * +---+---+---+---+
 * | 1 | 2 | 3 | 4 |
 * +---+---+---+---+
 * | 5 | 6 | 7 | 8 |
 * +---+---+---+---+
 * | 9 | 10| 11| 12|
 * +---+---+---+---+
 * 现在你要从中剪下5张来，要求必须是连着的。
 * （仅仅连接一个角不算相连）
 * 比如，【图2.jpg】，【图3.jpg】中，粉红色所示部分就是合格的剪取。
 * 【图2.jpg】
 * +---+---+---+---+
 * | 1 |=2=| 3 | 4 |
 * +---+---+---+---+
 * | 5 |=6=|=7=| 8 |
 * +---+---+---+---+
 * | 9 | 10|=11|=12|
 * +---+---+---+---+
 *
 *【图3.jpg】
 * +---+---+---+---+
 * | 1 | 2 |=3=| 4 |
 * +---+---+---+---+
 * |=5=|=6=|=7=| 8 |
 * +---+---+---+---+
 * | 9 |=10| 11| 12|
 * +---+---+---+---+
 *
 * 请你计算，一共有多少种不同的剪取方法。
 *
 * 请填写表示方案数目的整数。
 * 注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
 *
 */

#include <iostream>
#include <algorithm>
#include <set>
#include <array>

#define ROW    3
#define COLUMN 4

#define SIZE 5

using namespace std;

void n2xy(int n, int& x, int& y) {
    x = n / COLUMN;
    y = n % COLUMN;
}

int xy2n(int x, int y) {
    return x * COLUMN + y;
}

void show(const int arr[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i]+1 << " ";
    }
    cout << endl;
}

bool isValid(const int arr[SIZE], int pos, int n) {
    if (pos == 0)
        return true;
    int x, y;
    n2xy(n, x, y);
    for (int i = 0; i < pos; i++) {
        if (arr[i] == n)
            return false;
    }
    for (int i = 0; i < pos; i++) {
        int x1, y1;
        n2xy(arr[i], x1, y1);
        if (x == x1 && abs(y - y1) == 1)
            return true;
        if (y == y1 && abs(x - x1) == 1)
            return true;
    }
    return false;
}

void foo(int arr[SIZE], int pos, set<string>& s) {
    if (pos == SIZE) {
        int arr1[SIZE];
        memcpy(arr1, arr, SIZE * sizeof(int));
        sort(arr1, arr1+SIZE);
        string str;
        for (int i : arr1)
            str += to_string(i+1) + " ";
        s.insert(str);
        return;
    }
    for (int i = 0; i < ROW*COLUMN; i++) {
        int x, y;
        n2xy(i, x, y);
        if (!isValid(arr, pos, i))
            continue;
        arr[pos] = i;
        foo(arr, pos+1, s);
    }
}


int main() {
    int arr[SIZE];
    set<string> s;
    foo(arr, 0, s);
    for (const auto &str : s)
        cout << str << endl;
    cout << "sum is " << s.size() << endl;
    getchar();
    return 0;
}