#include <bits/stdc++.h>
using namespace std;

//  0123 4567 89
// (□□□□-□□□□)*□□=900
int data[10];
int main() {
    for (int i = 0; i < 10; i++) {
        data[i] = i;
    }

    do {
        if (data[0] == 0 or data[4] == 0 or data[8] == 0) {
            continue;
        }

        int a = data[0]*1000 + data[1]*100 + data[2]*10 + data[3];
        int b = data[4]*1000 + data[5]*100 + data[6]*10 + data[7];
        int c = data[8]*10 + data[9];
        if ((a-b)*c == 900) {
            cout << a << " " << b << " " << c << endl;
        }

    } while (next_permutation(data, data+10));


    return 0;
}