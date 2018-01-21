#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }


struct gun {
    int hurt, n;
    int acc_kind[1000];
};

int n, m;
gun guns[1000];
double acc[1000]; // accessories

int main() {
    rdIn("data.txt");
    while (cin >> n >> m) {
        memset(acc, 0, sizeof(acc));
        memset(guns, 0, sizeof(guns));
        for (int i = 0; i < n; i++) {
            gun gg;
            cin >> gg.hurt >> gg.n;
            for (int j = 0; j < gg.n; j++) {
                cin >> gg.acc_kind[j];
            }
            guns[i] = gg;
        }
        for (int i = 0; i < m; i++) {
            int kind; double hurt;
            cin >> kind >> hurt;
            acc[kind] = max(acc[kind], hurt);
        }

        double mx = 0;
        for (int i = 0; i < n; i++) {
            double sum = 1;
            for (int j = 0; j < guns[i].n; j++) {
                int kind = guns[i].acc_kind[j];
                sum += acc[kind];
            }
            sum *= guns[i].hurt;
            if (mx < sum)
                mx = sum;
        }
        printf("%.4f", mx);
    }

    return 0;
}