#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

int data[10000];
int data_size = 0;

int main() {
    rdIn("data.txt");

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a;
        if (a == 1) {
            reverse(data, data+data_size);
        } else if (a == 2) {
            data_size--;
        } else if (a == 3) {
            cin >> b;
            data[data_size++] = b;
        } else if (a == 4) {
            cout << data[0];
            for (int j = 1; j < data_size; j++) {
                cout << " " << data[j];
            }
            cout << endl;
        }
    }

    return 0;
}

/* test case
7
3 2
3 1
1
3 3
4
2
4
 */