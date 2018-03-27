#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int n = 20;
int data[20][2];

int dp(int index = 0, int left_space = 500) {
    if (index == n or left_space - data[index][0] < 0) {
        return 0;
    } else {
        return max(dp(index + 1, left_space), data[index][1] + dp(index + 1, left_space - data[index][0]));
    }
}


int main() {
    rdIn("data.txt");

    for (int i = 0; i < n; i++) {
        cin >> data[i][0] >> data[i][1];
    }

    cout << dp();


    return 0;
}