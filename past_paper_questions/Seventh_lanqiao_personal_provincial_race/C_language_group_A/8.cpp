/**
 *
 * 四平方和
 *
 * 四平方和定理，又称为拉格朗日定理：
 * 每个正整数都可以表示为至多4个正整数的平方和。
 * 如果把0包括进去，就正好可以表示为4个数的平方和。
 *
 * 比如：
 * 5 = 0^2 + 0^2 + 1^2 + 2^2
 * 7 = 1^2 + 1^2 + 1^2 + 2^2
 * （^符号表示乘方的意思）
 *
 * 对于一个给定的正整数，可能存在多种平方和的表示法。
 * 要求你对4个数排序：
 * 0 <= a <= b <= c <= d
 * 并对所有的可能表示法按 a,b,c,d 为联合主键升序排列，最后输出第一个表示法
 *
 *
 * 程序输入为一个正整数N (N<5000000)
 * 要求输出4个非负整数，按从小到大排序，中间用空格分开
 *
 * 例如，输入：
 * 5
 * 则程序应该输出：
 * 0 0 1 2
 *
 * 再例如，输入：
 * 12
 * 则程序应该输出：
 * 0 2 2 2
 *
 * 再例如，输入：
 * 773535
 * 则程序应该输出：
 * 1 1 267 838
 *
 * 资源约定：
 * 峰值内存消耗 < 256M
 * CPU消耗  < 3000ms
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
#include <cmath>
#include <ctime>

using namespace std;

bool foo(const int num, const int left, int arr[4], const int pos) {
//                                ~~~~
    // use left can reduce calculation, no need calculation left every loop
    if (pos == 4) {
        if (left == 0) {
            int i = 0;
            for (; i < 3; i++)
                cout << arr[i] << " ";
            cout << arr[i];
            return true;
        }
        return false;
    }
    int sqt = sqrt(left);
    for (int i = 0; i <= sqt; i++) {
        if (pos == 3)
            i = sqt - i;
//      ~~~~~~~~~~~~~~~~
        // why coding this ?
        // this code can save lots time
        // arr[3] is the biggest always,
        // so we think that `i` loop from `sqt` to `0` is more efficient than `i` loop from `0` to `sqt`
        arr[pos] = i;
        bool res = foo(num, left - i*i, arr, pos+1);
//                                 ~~~
        // `pow(i, 2)` spend time more than `i*i` spend time,
        // i use `pow(i, 2)` firstly, but when i use `i*i` to replace `pow(i, 2)`,
        // save lots of time immediately, but i don't know why.
        // see: https://stackoverflow.com/questions/6321170/is-there-any-advantage-to-using-powx-2-instead-of-xx-with-x-double
        if (res)
            return true;
    }


    return false;
}

int main() {
    time_t start, stop;
    start = time(nullptr);
    int num = 773535;
    int arr[4];
    foo(num, num, arr, 0);
    stop = time(nullptr);
    cout << endl << "spend time: " <<  stop - start << " s";
    return 0;
}