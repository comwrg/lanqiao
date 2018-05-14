#include <iostream>
#include <unordered_map>
using namespace std;

int data[4][4000];
unordered_map<int, int> sum;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d %d", &data[0][i], &data[1][i], &data[2][i], &data[3][i]);
        }

        sum.clear();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ++sum[data[0][i] + data[1][j]];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += sum[-(data[2][i] + data[3][j])];
            }
        }
        printf("%d\n", ans);
        if (t)
            printf("\n");
    }
    
    return 0;
}
