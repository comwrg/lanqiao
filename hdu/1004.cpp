/**
 * http://acm.hdu.edu.cn/showproblem.php?pid=1004
 */
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int main() {
    rdIn("data.txt");

    int n;
    while (~scanf("%d", &n)) {
        map<string, int> mp;
        for (int _ = 0; _ < n; _++) {
            char cball[1024];
            scanf("%s", cball);
            string ball(cball);
            if (mp.find(ball) == mp.end()) {
                mp.insert(make_pair(ball, 1));
            } else {
                mp[ball]++;
            }
        }
        auto cmp = [](pair<string, int> a, pair<string, int> b) {
            return a.second > b.second;
        };
        vector<pair<string, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), cmp);
        if (!vec.empty())
            cout << vec.begin()->first << endl;
    }


  
    return 0;
}