#include <bits/stdc++.h>
using namespace std;

bool handle(int n) {
    vector<int> v;
    while (n) {
        v.push_back(n % 10);
        n /= 10;
    }
    auto lt_min = min_element(v.begin(), v.end());
    int last;
    last = *v.begin();
    bool stat[2] = {0, 0};
    for (auto lt = v.begin()+1; lt <= lt_min; lt++) {
        stat[0] = 1;
        if (*lt >= last) {
            return false;
        }
        last = *lt;
    }
    last = *lt_min;
    for (auto lt = lt_min+1; lt < v.end(); lt++) {
        stat[1] = 1;
        if (*lt <= last) {
            return false;
        }
        last = *lt;
    }

    return stat[0] and stat[1];
}

int main() {
    int cnt = 0;
    for (int i = 100; i < 100000; i++) {
        if (handle(i)) {
            cout << i << endl;
            cnt++;
        }
    }

    cout << "ans:" << cnt ;

    return 0;
}