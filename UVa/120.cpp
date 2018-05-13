#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <queue>
using namespace std;

int data[30];

int main() {
    while (1) {
        int n = 0;
        data[0] = -1;
        while (~scanf("%d", &data[n])) {
            ++n;
            if (getchar() != ' ')
                break;
        }
        if (data[0] < 0)
            break;

        for (int i = 0; i < n; ++i) {
            printf("%d ", data[i]);
        }
        printf("\n");
        for (int i = n-1; i >= 0; --i) {
            auto it = max_element(data, data+i+1);
            int dis = distance(data, it);
            if (dis == i)
                continue;
            if (dis) {
                reverse(data, data+dis+1);
                printf("%d ", n-dis);
            }
            reverse(data, data+i+1);
            printf("%d ", n-i);
        }
        printf("0\n");
    }

                

    return 0;
}

