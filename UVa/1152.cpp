#include <iostream>
#include <map>
using namespace std;

int data[4][4000];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d %d", &data[0][i], &data[1][i], &data[2][i], &data[3][i]);
        }

        map<int, int> sum[2];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ++sum[0][data[0][i] + data[1][j]];
                ++sum[1][data[2][i] + data[3][j]];
            }
        }
        int ans = 0;
        for (auto it = sum[0].begin(); it != sum[0].end(); ++it) {
            ans += it->second * sum[1][-it->first];
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
