/**
 * Tour, ACM/ICPU SEERC 2005, UVa1347
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
int pass[1000];
int d[1000][1000];

double dist(int a, int b) {
    if (a < b)
        swap(a, b);
    if (d[a][b])
        return d[a][b];
    int side1 = data[a][0] - data[b][0];
    int side2 = data[a][1] - data[b][1];
    return sqrt(pow(side1, 2) + pow(side2, 2));
}

double foo(int a = 0, int b = 0) {
    if (a < b)
        swap(a, b);
    if (a == n-1) {
        return dist(a, b);
    }
    double d1 = dist(a, a+1);
    double d2 = dist(b, a+1);
    if (d1 < d2) {
        return d1 + foo(a+1, b); // point a -> point a+1
    } else {
        return d2 + foo(a, a+1); // point b -> point a+1
    }
}

int main() {
    rdIn("data.txt");

    while (cin >> n) {
        memset(data, 0, sizeof(data));
        memset(pass, 0, sizeof(pass));
        memset(d, 0, sizeof(d));

        for (int i = 0; i < n; i++) {
            cin >> data[i][0] >> data[i][1];
        }

        printf("%.2f\n", foo());
    }
  
    return 0;
}