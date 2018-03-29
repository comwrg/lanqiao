#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int main() {
    rdIn("data.txt");

    string data;
    cin >> data;
    set<string> ans;

    auto size = data.size();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 2; j++) {
            int left_border, right_border;
            // length of palindromic number is odd  if j == 0
            // length of palindromic number is even if j == 1
            left_border = right_border = i+j;
            while (left_border >= 0 and right_border < size
                   and data.at(left_border) == data.at(right_border)) {
                ans.insert(data.substr(left_border, right_border-left_border+1));
                left_border--; right_border++;
            }
        }
    }

    for (const auto &item : ans) {
        cout << item << endl;
    }


    return 0;
}