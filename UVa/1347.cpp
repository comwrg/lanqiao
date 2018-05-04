/**
 * Tour, ACM/ICPC SEERC 2005, UVa1347
 *
 * Sample Input
 * 3 1 1 2 3 3 1 4 1 1 2 3 3 1 4 2
 *
 * Sample Output
 * 6.47 7.89
 */
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }

int n;
int data[1000][2];
double d[1000][1000];

double dist(int a, int b) {
    int side1 = data[a][0] - data[b][0];
    int side2 = data[a][1] - data[b][1];
    return sqrt(pow(side1, 2) + pow(side2, 2));
}

int main() {
    rdIn("data.txt");

    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> data[i][0] >> data[i][1];
        }

        // i > j must
        for (int i = n-1; i > 0; --i) {
            for (int j = 0; j < i; ++j) {
                if (i == n-1) {
                    d[i][j] = dist(n-1, j);
                } else {
                    d[i][j] = min(d[i+1][i] + dist(i+1, j), d[i+1][j] + dist(i+1, i));
                }
            }
        }
        d[0][0] = d[1][0] + dist(0, 1);

        printf("%.2f\n", d[0][0]);
    }
  
    return 0;
}
