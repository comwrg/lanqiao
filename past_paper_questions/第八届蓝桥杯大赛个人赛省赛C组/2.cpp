#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

map<int, int> mp;
vector<int> v;

void count(string filename, int m = 0) {
    fin.open(filename);
    cin.rdbuf(fin.rdbuf());
    int id; char c;
    while (cin >> id >> c) {
        if (m == 0) {
            mp[id]++;
        } else {
            v.push_back(id);
        }
    }
    fin.close();
}

int main() {
    count("../C语言C组/2/A.txt");
    count("../C语言C组/2/B.txt");
    count("../C语言C组/2/C.txt", 1);

    int cnt = 0;
    for (int i : v) {
        auto lt = mp.find(i);
        if (lt != mp.end() and lt->second == 2) {
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}