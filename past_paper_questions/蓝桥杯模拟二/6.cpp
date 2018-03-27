#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

struct Node {
    int begin, end;
};

vector<Node> vec;
bool data[1000];

bool conflict(Node n) {
    for (int i = n.begin; i < n.end; i++) {
        if (data[i-1]) {
            return true;
        }
    }
    return false;
}

void realize(Node n, bool b) {
    for (int i = n.begin; i < n.end; i++) {
        data[i-1] = b;
    }
}

int foo(int index = 0) {
    if (index >= vec.size()) {
        return 0;
    }
    int r1 = -1;
    if (!conflict(vec.at(index))) {
        realize(vec.at(index), true);
        r1 = 1 + foo(index+1);
        realize(vec.at(index), false);
    }

    int r2 = foo(index+1);
    return max(r1, r2);
}

int main() {
    rdIn("data.txt");

    Node n;
    while (~scanf("%d %d", &n.begin, &n.end)) {
        vec.push_back(n);
    }
    memset(data, 0, sizeof(data));
    cout << foo();

    return 0;
}