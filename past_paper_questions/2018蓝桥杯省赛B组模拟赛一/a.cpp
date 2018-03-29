#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int i = 10; i < 100; i++) {
        for (int j = 10; j < 100; j++) {
            int sum1 = i/10 + i%10;
            int sum2 = j/10 + j%10;
            if (i == 2*sum2 and j == 3*sum1) {
                cout << i << " " << j << endl;
            }
        }
    }

    return 0;
}