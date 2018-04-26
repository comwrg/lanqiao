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
int dp1[NMAX];

// max value of first `course` spend `days` days
int foo(int course, int days) {
    if (course < 1)
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
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &profit[i][j]);
            }
        }
        // recursive
        memset(dp, 0, sizeof(dp));
        printf("%d\n", foo(n, m));
        // ----

        // loop
        memset(dp1, 0, sizeof(dp1));
        for (int i = 1; i <= n; ++i) { // loop ith course
            for (int j = m; j >= 0; --j) { // use j minutes total first i courses
                for (int k = 1; k <= j; ++k) { // give ith course k minutes, so give first i-1 courses j-k minutes
                    dp1[j] = max(dp1[j], dp1[j-k]+profit[i][k]);
                }
            }
        }
        printf("%d\n", dp1[m]);
        // ----
    }

  
    return 0;
}