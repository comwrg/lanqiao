#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

long long cache[310][310];

long long dp(int n, int k) {
    if (cache[n][k])
        return cache[n][k];
    if (n == 1 or k == 1)
        return 1;
    if (k > n)
        return cache[n][k] = dp(n, n);
    if (k == n)
        return cache[n][k] = dp(n, k-1) + 1;
    return cache[n][k] = dp(n, k-1) + dp(n-k , k);
}

int main() {
    rdIn("data.txt");

    memset(cache, 0, sizeof(cache));
    int n, k;
    cin >> n >> k;
    cout << dp(n, k);


    return 0;
}