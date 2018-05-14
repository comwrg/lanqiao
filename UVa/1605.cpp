#include <iostream>
using namespace std;

// 方法是紫书上的， 觉得方法很巧妙
int main() {
    char chs[26*2];
    for (int i = 0; i < 26; ++i) {
        chs[i] = 'a' + i;
        chs[i+26] = 'A' + i;
    }

    int n;
    int ans[50][50];
    while (~scanf("%d", &n)) {
        printf("2 %d %d\n", n, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%c", chs[i]);
            }
            printf("\n");
        }
        printf("\n");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%c", chs[j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
