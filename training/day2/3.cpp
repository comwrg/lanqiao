/**
 * http://acm.hdu.edu.cn/showproblem.php?pid=1022
 */
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

#define IN  0
#define OUT 1
int n;
char data[2][10];
vector<int> record(20);
stack<char> stk;

int main() {
    rdIn("data.txt");

    while (~scanf("%d", &n)) {
        scanf("%s", data[IN]);
        scanf("%s", data[OUT]);

        record.clear();
        while (!stk.empty()) {
            stk.pop();
        }
        int i = 0, j = 0;
        while (j < n) {
            if (stk.empty()) {
                // the stack is empty have no choice only to push
                if (i >= n) {
                    // fail
                    break;
                }
                stk.push(data[IN][i++]);
                record.push_back(IN);
            }
            if (stk.top() == data[OUT][j]) {
                // pop if equal
                j++;
                stk.pop();
                record.push_back(OUT);
            } else {
                // not equal, so push continue
                 if (i >= n) {
                     break;
                 }
                stk.push(data[IN][i++]);
                record.push_back(IN);
            }
        }

        if (record.size() == 2 * n) {
            printf("Yes.\n");
            for (int v : record) {
                if (v == IN) {
                    printf("in\n");
                } else {
                    printf("out\n");
                }
            }
        } else {
            printf("No.\n");
        }

        printf("FINISH\n");
    }

    return 0;
}