#include <bits/stdc++.h>
using namespace std;

const int n = 101;
const int mid = n/2;
bool isin(int x, int y) {
    return abs(x-mid) + abs(y-mid) <= mid;
}

int main() {

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isin(i, j)) {
                printf("%d, %d\n", i, j);
                sum += i*n + j+1;
            }
        }
    }
    cout << sum << endl;


    return 0;
}