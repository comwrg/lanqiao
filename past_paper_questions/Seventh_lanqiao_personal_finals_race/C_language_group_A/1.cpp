/**
 *
 * 随意组合
 *
 * 小明被绑架到X星球的巫师W那里。
 *
 * 其时，W正在玩弄两组数据 (2 3 5 8) 和 (1 4 6 7)
 * 他命令小明从一组数据中分别取数与另一组中的数配对，共配成4对（组中的每个数必被用到）。
 * 小明的配法是：{(8,7),(5,6),(3,4),(2,1)}
 *
 * 巫师凝视片刻，突然说这个配法太棒了！
 *
 * 因为：
 * 每个配对中的数字组成两位数，求平方和，无论正倒，居然相等：
 * 87^2 + 56^2 + 34^2 + 21^2  =  12302
 * 78^2 + 65^2 + 43^2 + 12^2  =  12302
 *
 * 小明想了想说：“这有什么奇怪呢，我们地球人都知道，随便配配也可以啊！”
 * {(8,6),(5,4),(3,1),(2,7)}
 *
 * 86^2 + 54^2 + 31^2 + 27^2 = 12002
 * 68^2 + 45^2 + 13^2 + 72^2 = 12002
 *
 * 巫师顿时凌乱了。。。。。
 *
 * 请你计算一下，包括上边给出的两种配法，巫师的两组数据一共有多少种配对方案具有该特征。
 * 配对方案计数时，不考虑配对的出现次序。
 * 就是说：
 * {(8,7),(5,6),(3,4),(2,1)}
 * 与
 * {(5,6),(8,7),(3,4),(2,1)}
 * 是同一种方案。
 *
 * 注意：需要提交的是一个整数，不要填写任何多余内容（比如，解释说明文字等）
 *
 */

#include <iostream>
#include <cmath>

#define ROW    4
#define COLUMN 2

using namespace std;

const int data[4] = {2, 3, 5, 8};
int mark[4] = {0, 0, 0, 0};
int arr[ROW][COLUMN];

void show() {
    for (int i = 0; i < ROW; i++) {
        printf("(%d, %d) ", arr[i][0], arr[i][1]);
    }
    cout << endl;
}

bool isValid(int& sum) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < ROW; i++) {
        string s1 = to_string(arr[i][0]);
        string s2 = to_string(arr[i][1]);
        string s;
        s = s1 + s2;
        int num1 = atoi(s.c_str());
        sum1 += pow(num1, 2);

        s = s2 + s1;
        int num2 = atoi(s.c_str());
        sum2 += pow(num2, 2);
    }
    sum = sum1;
    return sum1 == sum2;
}

int sum = 0;
void foo(int pos) {
    if (pos >= 4) {
        int n;
        if (isValid(n)) {
            cout << ++sum << "\t" << n << endl;
            show();
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (mark[i] != 0)
            continue;
        mark[i] = 1;
        arr[pos][0] = data[i];
        foo(pos + 1);
        mark[i] = 0;
    }
}

int main() {
    arr[0][1] = 1;
    arr[1][1] = 4;
    arr[2][1] = 6;
    arr[3][1] = 7;

    foo(0);
    return 0;
}