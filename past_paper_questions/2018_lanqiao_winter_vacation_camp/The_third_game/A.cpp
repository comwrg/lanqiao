#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
/**
 * emmm.
 * 第一次知道斯特林公式, 是  sqrt(2 * PI * n) * (n / e)**n;
 * 第一次知道一个数的位数是 (int)log10(n) + 1, 同理8进制的就是 (int)log8(n) + 1
 *
 * 那么8进制的位数就是
 * (int)log8( sqrt(2 * PI * n) * (n / e)**n ) + 1
 * 其中 log8( sqrt(2 * PI * n) * (n / e)**n
 *   = log8( sqrt(2 * PI * n) ) + log8[(n / e) ** n]
 *   = log8(2 * PI * n)/2 + log8(n / e)*n
 * 然后，在C++中并没有log8， 用换底公式
 *   = log(2 * PI * n) / log(8) / 2 + log(n / e) / log(8) * n
 *   = [log(2 * PI * n) / 2 + log(n / e) * n] / log(8)
 *
 *
 * ..小插曲
 * 写 cin, cout 就超时..
 * 但是改成 scanf, printf 就可以通过
 * 好无语啊..................
 */

int foo(int n) {
    if (n == 0)
        return 1;
    return (log(2 * M_PI * n) / 2 + log(n / M_E) * n) / log(8) + 1;
}

int main() {
    rdIn("data.txt");
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        printf("%d\n", foo(m));
    }
    return 0;
}