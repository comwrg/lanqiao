/**
 * http://acm.hdu.edu.cn/showproblem.php?pid=1013
 */
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }
typedef long long LL;

int handle(int n) {
    if (n < 10) {
        return n;
    }
    int root = 0;
    while (n) {
        int m = n % 10;
        n /= 10;
        root += m;
    }
    return handle(root);
}

int handle(const char *ch) {
    int index = 0;
    char c;
    int root = 0;
    while ((c = ch[index++]) != '\0') {
        int n = c - 48;
        root += n;
    }
    return handle(root);
}

int main() {
    rdIn("data.txt");

    char ch[1024];
    while (~scanf("%s", ch) and ch[0] != '0') {
        int root = handle(ch);
        printf("%d\n", root);
    }
  
  
    return 0;
}