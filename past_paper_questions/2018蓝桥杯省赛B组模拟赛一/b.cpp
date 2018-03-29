#include <bits/stdc++.h>
using namespace std;

int main() {
    bool stat[1001]; // not use 0
    fill(stat, stat+1001, 1);
    for (int i = 1; i < 1001; i++) {
        if (i % 3 == 0) {
            stat[i] = !stat[i];
        }

        if (i % 5 == 0) {
            stat[i] = !stat[i];
        }

        if (i % 7 == 0) {
            stat[i] = !stat[i];
        }
    }

    int n = 0;
    for (int i = 1; i < 1001; i++) {
        if (stat[i]) {
            n++;
        }
    }
    cout << n;
    return 0;
}