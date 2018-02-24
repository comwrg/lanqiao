#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

struct card {
    int s, t, x;
    card() {}
    card(int s, int t, int x) : s(s), t(t), x(x) {}
};

stack<card> data;
int hurt;

void handle() {
    while (!data.empty()) {
        card tp = data.top();
        switch (tp.t) {
            case 1:
                debug("hurt += tp.x(%d)\n", tp.x);
                hurt += tp.x;
                data.pop();
                break;
            case 2:
                debug("hurt += tp.x(%d) * data.size()(%d)\n", tp.x, data.size());
                hurt += tp.x * data.size();
                data.pop();
                break;
            case 3:
                debug("empty data\n");
                while (!data.empty()) {
                    data.pop();
                }
                break;
            case 4:
                debug("pop 2 times\n");
                data.pop();
                if (!data.empty()) {
                    data.pop();
                }
                break;
        }
    }
}

int main() {
    rdIn("data.txt");

    int n;
    while (~scanf("%d", &n)) {
        hurt = 0;
        for (int i = 0; i < n; i++) {
            card c;
            scanf("%d%d", &c.s, &c.t);
            if (c.t == 1 or c.t == 2) {
                scanf("%d", &c.x);
            }

            if (!data.empty() and c.s < data.top().s) {
                handle();
            }
            data.push(c);
            debug("data.push(c)\n");
        }
        handle();
        printf("%d\n", hurt);
    }


    return 0;
}