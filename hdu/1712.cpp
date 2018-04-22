#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int NMAX = 101;
// n courses, m days
int n, m;
// profit[i][j], profit in course i spend j days
int profit[NMAX][NMAX];
int dp[NMAX][NMAX];

// max value of first `course` spend `days` days
int foo(int course, int days) {
    if (course < 0)
        return 0;
    if (dp[course][days])
        return dp[course][days];
    for (int spend = 1; spend <= days; ++spend) {
         int r = max(foo(course-1, days),
                     foo(course-1, days-spend) + profit[course][spend]);
        dp[course][days] = max(dp[course][days], r);
    }
    return dp[course][days];
}

int main() {
    rdIn("data.txt");

    while (~scanf("%d %d", &n, &m) and n) {
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &profit[i][j]);
            }
        }

        printf("%d\n", foo(n, m));
    }

  
    return 0;
}