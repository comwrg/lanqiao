#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }

int main() {
    rdIn("data.txt");
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        long long  a = 0, b = 1;
        for (int j = 0; j < m-1; j++) {
            auto c = a + b;
            a = b;
            b = c;
        }
        cout << a + b << endl;
    }
    return 0;
}