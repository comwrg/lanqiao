#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int a, b, n;
int data[50];

int f(int n) {
    if (data[n] > -1)
        return data[n];
    if (n < 3)
        return 1;
    // f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.
    return (a*f(n-1) + b*f(n-2)) % 7;
}

int main() {
    rdIn("data.txt");

    while (~scanf("%d %d %d", &a, &b, &n) and n) {
        memset(data, -1, sizeof(data));
        for (int i = 1; i < 50; i++) {
            data[i] = f(i);
        }

        printf("%d\n", f(n % 49));
    }

    return 0;
}