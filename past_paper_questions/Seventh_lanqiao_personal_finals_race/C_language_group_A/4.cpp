/**
 *
 * 路径之谜
 *
 * 小明冒充X星球的骑士，进入了一个奇怪的城堡。
 * 城堡里边什么都没有，只有方形石头铺成的地面。
 *
 * 假设城堡地面是 n x n 个方格。【如图1.png】所示。
 *
 *      [2] [4] [3] [4]
 *     +---+---+---+---+
 * [4] | | | ------->| |
 *     +-v-+-^-+---+-|-+
 * [3] | --->| |   | | |
 *     +---+---+---+-v-+
 * [3] |   | |<------- |
 *     +---+-v-+---+---+
 * [3] |   | --------> |
 *     +---+---+---+---+
 *
 *
 * 按习俗，骑士要从西北角走到东南角。
 * 可以横向或纵向移动，但不能斜着走，也不能跳跃。
 * 每走到一个新方格，就要向正北方和正西方各射一箭。
 * （城堡的西墙和北墙内各有 n 个靶子）
 *
 *
 * 同一个方格只允许经过一次。但不必走完所有的方格。
 *
 * 如果只给出靶子上箭的数目，你能推断出骑士的行走路线吗？
 *
 * 有时是可以的，比如图1.png中的例子。
 *
 * 本题的要求就是已知箭靶数字，求骑士的行走路径（测试数据保证路径唯一）
 *
 * 输入：
 * 第一行一个整数N(0<N<20)，表示地面有 N x N 个方格
 * 第二行N个整数，空格分开，表示北边的箭靶上的数字（自西向东）
 * 第三行N个整数，空格分开，表示西边的箭靶上的数字（自北向南）
 *
 * 输出：
 * 一行若干个整数，表示骑士路径。
 *
 * 为了方便表示，我们约定每个小格子用一个数字代表，从西北角开始编号: 0,1,2,3....
 * 比如，图1.png中的方块编号为：
 *
 * 0  1  2  3
 * 4  5  6  7
 * 8  9  10 11
 * 12 13 14 15
 *
 *
 * 示例：
 * 用户输入：
 * 4
 * 2 4 3 4
 * 4 3 3 3
 *
 * 程序应该输出：
 * 0 4 5 1 2 3 7 11 10 9 13 14 15
 *
 *
 * 资源约定：
 * 峰值内存消耗 < 256M
 * CPU消耗  < 1000ms
 *
 * 请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。
 *
 * 所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
 *
 * 注意: main函数需要返回0
 * 注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
 * 注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。
 *
 * 提交时，注意选择所期望的编译器类型。
 */

#include <iostream>

using namespace std;

int n;
int times[2][20];

int xy2n(const int x, const int y) {
    return x * n + y;
}

bool allZero() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (times[i][j] != 0)
                return false;
        }
    }
    return true;
}

void foo(const int nextX = 0, const int nextY = 0, const string& path = "") {
    if (nextX < 0 || nextX >= n)
        return;
    if (nextY < 0 || nextY >= n)
        return;

    string nStr = to_string(xy2n(nextX, nextY));
    if (path.find(nStr) != string::npos)
        // used
        return;

    int& timesX = times[1][nextX];
    int& timesY = times[0][nextY];
    if (timesX <= 0 || timesY <= 0)
        return;


    // code A, need resume later
    timesX--; timesY--;

    string newPath = path + nStr + " ";
    if (nextX == n-1 && nextY == n-1) {
        // valid
        if (allZero()) {
            // erase the last blank
            newPath.erase(newPath.length()-1);
            cout << newPath << endl;
        }
    } else {
        // tempted
        foo(nextX, nextY+1, newPath);
        foo(nextX, nextY-1, newPath);
        foo(nextX+1, nextY, newPath);
        foo(nextX-1, nextY, newPath);
    }

    // resume code A
    timesX++; timesY++;
}

int main() {
    /*
     * 4
     * 2 4 3 4
     * 4 3 3 3
     */
    cin >> n;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> times[i][j];
        }
    }

    foo();
    return 0;
}