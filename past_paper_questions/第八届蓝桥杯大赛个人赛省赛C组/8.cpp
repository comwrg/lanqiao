// DO NOT KNOW THE CODE IS CORRECT OR NOT
#include <bits/stdc++.h>
using namespace std;
ifstream fin; void rdIn(const string& filename) {fin.open(filename); if (fin.good()) { cin.rdbuf(fin.rdbuf()); freopen(filename.c_str(), "r", stdin); } }
void debug(const char * __format, ...) { if (!fin.good()) return; va_list argv; __builtin_va_start(argv, __format); vprintf(__format, argv); va_end(argv); }

const int base[3][3] = {
        4, 9, 2,
        3, 5, 7,
        8, 1, 6,
};

int data[3][3];
int input[3][3];

void mirror() {
    for (int i = 0; i < 3; i++)
        swap(data[i][0], data[i][2]);
}

void whirl() {
    int cp[3][3];
    memcpy(cp, data, sizeof(data));
    for (int i = 0; i < 3; i++) {
        data[0][i] = cp[2-i][0];
        data[i][2] = cp[0][i];
        data[2][i] = cp[2-i][2];
        data[i][0] = cp[2][i];
    }
}

bool same() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (input[i][j] == 0)
                continue;
            if (data[i][j] != input[i][j])
                return false;
        }
    }
    return true;
}

void show() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    rdIn("data.txt");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> input[i][j];
        }
    }

    int ans[3][3];
    int times = 0;
    memcpy(data, base, sizeof(data));
    for (int i = 0; i < 3; i++) {
        whirl();
        if (same()) {
            memcpy(ans, data, sizeof(data));
            times++;
            break;
        }
        mirror();
        if (same()) {
            memcpy(ans, data, sizeof(data));
            times++;
            break;
        }
        mirror();
    }

    if (times > 1) {
        printf("Too Many\n");
    } else {
        show();
    }

    return 0;
}