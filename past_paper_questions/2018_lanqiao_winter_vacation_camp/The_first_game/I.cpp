#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }

bool is_include(int i, const set<char>& hate) {
    string i_str = to_string(i);
    for (char c : hate) {
        if (i_str.find(c) != string::npos)
            return true;
    }
    return false;
}

int foo(int a, int b) {
    set<char> hate;
    string a_str = to_string(a);
    string b_str = to_string(b);
    for (char c : a_str) {
        hate.insert(c);
    }
    for (char c : b_str) {
        hate.insert(c);
    }

    int sum = 0;
    for (int i = 1; i <= 1000; i++) {
        if (is_include(i, hate))
            continue;
        if (i > a && i % a == 0)
            continue;
        if (i > b && i % b == 0)
            continue;
//        cout << i << ",";
        sum++;
    }
    return sum;
}

int main() {
    rdIn("data.txt");
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << foo(a, b) << endl;
    }

    return 0;
}