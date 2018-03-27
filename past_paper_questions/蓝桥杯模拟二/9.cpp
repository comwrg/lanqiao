#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

class BigInt {
public:
    BigInt() {
        memset(v, 0, sizeof(v));
    }
    BigInt(string s) : BigInt() {
        for (int i = s.size()-1; i >= 0; i--) {
            char c = s.at(i);
            this->new_pos(c - '0');
        }
    }
    BigInt(int i) : BigInt(to_string(i))  {

    }

    BigInt operator+(const BigInt &rhs) {
        BigInt res;
        for (int i = 0; i < max(this->p, rhs.p); i++) {
            res.new_pos(v[i] + rhs.v[i]);
        }
        return res;
    }

    BigInt operator*(const int i) {
        BigInt res;
        for (int j = 0; j < p; j++) {
            res.new_pos(i * this->v[j]);
        }
        return res;
    }

    void carry() {
        for (int i = 0; i < p; i++) {
            if (v[i] > 9) {
                v[i+1] += v[i] / 10;
                v[i] %= 10;
            }
        }
        while (v[p-1] > 9) {
            v[p] += v[p-1] / 10;
            v[p-1] %= 10;
            p++;
        }
    }

    void println() {
        for (int i = p-1; i >= 0; i--) {
            printf("%d", v[i]);
        }
        printf("\n");
    }

private:
    int v[1024];
    int p = 0;
    void new_pos(int i) {
        v[p++] = i;
    }
};

const int mod = 10e9+7;
int a, b, c;
int data[3] = {1, 2};
string n;

void calc() {
    data[2] = a*data[1] + b*data[0] + c;
    data[0] = data[1];
    data[1] = data[2];
}

int main() {
    rdIn("data.txt");
    cin >> n;
    cin >> a >> b >> c;

    for (int i = 0; i < n-3; i++) {

    }

    return 0;
}