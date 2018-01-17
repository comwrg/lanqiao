/**
 *
 * 最大比例
 *
 * X星球的某个大奖赛设了M级奖励。每个级别的奖金是一个正整数。
 * 并且，相邻的两个级别间的比例是个固定值。
 * 也就是说：所有级别的奖金数构成了一个等比数列。比如：
 * 16,24,36,54
 * 其等比值为：3/2
 *
 * 现在，我们随机调查了一些获奖者的奖金数。
 * 请你据此推算可能的最大的等比值。
 *
 * 输入格式：
 * 第一行为数字 N (0<N<100)，表示接下的一行包含N个正整数
 * 第二行N个正整数Xi(Xi<1 000 000 000 000)，用空格分开。每个整数表示调查到的某人的奖金数额
 *
 * 要求输出：
 * 一个形如A/B的分数，要求A、B互质。表示可能的最大比例系数
 *
 * 测试数据保证了输入格式正确，并且最大比例是存在的。
 *
 * 例如，输入：
 * 3
 * 1250 200 32
 *
 * 程序应该输出：
 * 25/4
 *
 * 再例如，输入：
 * 4
 * 3125 32 32 200
 *
 * 程序应该输出：
 * 5/2
 *
 * 再例如，输入：
 * 3
 * 549755813888 524288 2
 *
 * 程序应该输出：
 * 4/1
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
#include <algorithm>
#include <cmath>

using namespace std;

struct fraction {
    long long molecular;
    long long denominator;
    fraction() : molecular(0), denominator(0) {}
    fraction(long long m, long long d) : molecular(m), denominator(d) {}
};

long long findGreatestCommonDivisor(long long a, long long b) {
    for (long long i = min(a, b); i >= 0; i--)
        if (a % i == 0 && b % i == 0)
            return i;
}

long long log(long long x, long long base) {
    long long n = 1;
    for (long long i = 1; i <= x; i++) {
        n *= base;
        if (n == x)
            return i;
    }
    return 0;
}

long long min(const long long arr[], int len) {
    long long min = arr[0];
    for (int i = 0; i < len; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

long long findSameBase(const long long arr[], const int len) {
    long long qarr[len-1];
    long long arrCopy[len];
    memcpy(arrCopy, arr, sizeof(arrCopy));
    // reverse sort
    sort(arrCopy, arrCopy+len); reverse(arrCopy, arrCopy+len);
    for (int i = 0; i < len-1; i++) {
        qarr[i] = arr[i] / arr[i+1];
        // mean `arr[i]` equal to `arr[i+1]`
        if (qarr[i] == 1)
            qarr[i] = arr[i];
    }
    // set minimum is base
    long long base = min(qarr, len-1);
    for (int i = 0; i < len; i++) {
        // to check out that base is valid.
        long long logarithm = log(arr[i], base);
        // if logarithm equal to zero, that's mean cannot find logarithm, the base is not valid
        if (logarithm == 0) {
            // square root base
            base = sqrt(base);
            // set `i` is -1 to make the loop restart
            i = -1;
        }
    }
    return base;
}

fraction findMaxBase(const fraction arr[], const int len) {
    long long marr[len], darr[len];
    int flen = len;
    int index = 0;
    for (int i = 0; i < len; i++) {
        // mean molecular and denominator equal one both
        if (arr[i].molecular == arr[i].denominator) {
            flen--;
            continue;
        }
        marr[index] = arr[i].molecular;
        darr[index] = arr[i].denominator;
        index++;
    }
    fraction f(findSameBase(marr, flen), findSameBase(darr, flen));
    return f;
}

int main() {
    /**
     * step:
     *          e.g.{549755813888, 524288, 2}
     * 1. reverse order.    e.g.{549755813888, 524288, 2}
     * 2. pairwise.         e.g.{549755813888/524288, 524288/2}
     * 3. simply.           e.g.{1048576/1, 262144/1}
     * 4. reorganization, molecular and molecular together,
     *    denominator and denominator together.              e.g.{
     *                                                                {1048576, 1}, // group molecular
     *                                                                {262144, 1},  // group denominator
     *                                                           }
     * 5. handle group molecular
     *      5.1. reverse order. e.g.{1048576, 262144}
     *      5.2. pairwise.      e.g.{1048576 / 262144}
     *      5.3. divided, have a situation need attention,
     *           if molecular equal to denominator, set the result is molecular. e.g.{4}
     *      5.4. judgment that the logarithm of A to B whether a integer.
     *           A belongs to the result of reverse order, e.g.{1048576, 262144}.
     *           B is the result of divided.
     *           if not have a integer, square root the result of divider and try again.
     *
     * 6. handle group denominator same with handle group molecules
     * 7. combine the result of handle group molecular and the result of handle group denominator.
     */
    int len = 4;
//    long long arr[len] = {1250, 200, 32};
//    long long arr[len] = {549755813888, 524288, 2};
    long long arr[len] = {16, 24, 36, 54};
    // reverse order
    sort(arr, arr+len); reverse(arr, arr+len);
    fraction farr[len];
    for (int i = 0; i < len-1; i++) {
        // find greatest common divisor for simple fraction
        long long divisor = findGreatestCommonDivisor(arr[i], arr[i+1]);
        // pairwise
        fraction f(arr[i] / divisor, arr[i+1] / divisor);
        cout << f.molecular << " / " << f.denominator << endl;
        farr[i] = f;
    }
    fraction f = findMaxBase(farr, len-1);
    cout << f.molecular << " / " << f.denominator;

    return 0;
}