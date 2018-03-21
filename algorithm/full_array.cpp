// 全排列
#include <iostream>
using namespace std;

int n = 5;
char data[] = {'A', 'B', 'C', 'D', 'E'};

void full_array(const int start = 0) {
    if (start == n) {
        for (char c : data) {
            cout << c;
        }
        cout << endl;
        return;
    }
    for (int i = start; i < n; i++) {
        swap(data[start], data[i]);
        full_array(start + 1);
        swap(data[start], data[i]);
    }
}

int main() {
    full_array();
    return 0;
}