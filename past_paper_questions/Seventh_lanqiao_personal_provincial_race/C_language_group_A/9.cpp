/**
 *
 * 密码脱落
 *
 * X星球的考古学家发现了一批古代留下来的密码。
 * 这些密码是由A、B、C、D 四种植物的种子串成的序列。
 * 仔细分析发现，这些密码串当初应该是前后对称的（也就是我们说的镜像串）。
 * 由于年代久远，其中许多种子脱落了，因而可能会失去镜像的特征。
 *
 * 你的任务是：
 * 给定一个现在看到的密码串，计算一下从当初的状态，它要至少脱落多少个种子，才可能会变成现在的样子。
 *
 * 输入一行，表示现在看到的密码串（长度不大于1000）
 * 要求输出一个正整数，表示至少脱落了多少个种子。
 *
 * 例如，输入：
 * ABCBA
 * 则程序应该输出：
 * 0
 *
 * 再例如，输入：
 * ABDCDCBABC
 * 则程序应该输出：
 * 3
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
#include <cstdlib>
#include <ctime>

using namespace std;

#define FILL_DIRECTION_LEFT_TO_RIGHT true
#define FILL_DIRECTION_RIGHT_TO_LEFT false

int foo(const string& s, const int refBit, bool fillDirection) {
    int leftPoint = refBit - 1;
    int rightPoint = refBit + 1;
    int patch = 0;
    while(leftPoint >= 0 && rightPoint < s.length()) {
        if (s[leftPoint] == s[rightPoint]) {
            leftPoint--; rightPoint++;
        } else {
            if (fillDirection) {
                rightPoint++;
            } else {
                leftPoint--;
            }
            patch++;
        }
    }
//    printf("left point: %d, right point: %d\n", leftPoint, rightPoint);
//    printf("patch: %d\n", patch);
    int leftPatch = leftPoint + 1;
    leftPatch = abs(leftPatch);
    int rightPatch = rightPoint - s.length();
    rightPatch = abs(rightPatch);
//    printf("left patch: %d, right patch: %d\n", leftPatch, rightPatch);
    patch += leftPatch + rightPatch;
//    printf("patch: %d\n", patch);
    return patch;
}

int main() {
    /**
                v
     * ABDCDCABAC
      ^
     */
    string s = "ABDCDCBABC";
    int min = s.length();
    for (int i = 0; i < s.length(); i++) {
        int v;
        v = foo(s, i, FILL_DIRECTION_LEFT_TO_RIGHT);
        if (v < min)
            min = v;
        v = foo(s, i, FILL_DIRECTION_RIGHT_TO_LEFT);
        if (v < min)
            min = v;
    }
    cout << min << endl;
    cout << static_cast<double>(clock()) / CLOCKS_PER_SEC << " s";
    return 0;
}