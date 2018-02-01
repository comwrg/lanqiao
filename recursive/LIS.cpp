#include <bits/stdc++.h>
using namespace std;

int LIS(const int data[], const int len) {
    int dp[len];
    for (int i = len-1; i >= 0; i--) {
        dp[i] = 1;
        for (int j = i+1; j < len; j++) {
            if (data[i] < data[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return distance(dp, max_element(dp, dp+len));
}

int main() {
    int data[] = {1, 6, 2, 3, 7, 5};
    const int LEN = sizeof(data) / sizeof(int);
    int longest_index = LIS(data, LEN);
    cout << longest_index << endl;
    return 0;
}