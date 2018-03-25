#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int n = 8;
int data[n];

int arr2int() {
    int r = 0;
    for (int i = 0; i < n; i++) {
        r += data[i] * pow(10, i);
    }
    return r;
}

bool prime(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    rdIn("data.txt");

    for (int i = 0; i < n; i++) {
        data[i] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    int cnt = 0;
    do {
        if (data[n-1] == 0) {
            continue;
        }
        if (prime(arr2int())) {
            cnt++;
        }
    } while (next_permutation(data, data+n));

    cout << cnt << endl;



    return 0;
}