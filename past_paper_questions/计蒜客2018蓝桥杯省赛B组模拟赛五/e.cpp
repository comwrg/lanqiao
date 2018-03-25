#include <iostream>
using namespace std;
int main() {
    int n, ans = 0;
    n = 5;
    while (n) {
        /*
         * 标程中的讲解 我觉得不错
         * 对于一个数的阶乘(分解成多个素数相乘)，如果想末尾出现 0 的话，只有当 5 和 2 出现的时候，才会在末尾出现 0 。
         * 因为 2 的个数一定比 5 多。所以我们就可以得出一个结论，一个数的阶乘，末尾 0 的个数就是看里面 5 的个数。
         * 现在变成求 1 到 n 的因子有多少个 5。对于包含 1 个 5 的数字，就是 n/5，包含两个 5 的数字个数为 n / 25。。。通过 n = n / 5 的方式，每次剥掉一层 5。
         */
        ans += n/=5;
    }
    cout << ans << endl;
    return 0;
}
/*
def zero(n):
    sum = 1
    for i in range(1, n+1):
        sum *= i
    sum = str(sum)
    print(n,  end=' ')
    i = -1
    while sum[i] == '0':
        i -= 1
    return abs(i+1)

print(zero(10000))
# 5, 10, 15, 20, 25, 30, 35, 40,
 */

