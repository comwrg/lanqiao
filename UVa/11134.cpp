#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


struct node {
    int l, r, idx, v;
} x[5000], y[5000];

bool comp_r(const node &lhs, const node &rhs) {
    return lhs.r < rhs.r;
}

bool comp_idx(const node &lhs, const node &rhs) {
    return lhs.idx < rhs.idx;
}

int main() {
    int t;
    bool vis[5000];
    while (~scanf("%d", &t) and t) {
        for (int i = 0; i < t; ++i) {
            scanf("%d %d %d %d", &x[i].l, &y[i].l, &x[i].r, &y[i].r);
            x[i].idx = y[i].idx = i;
            x[i].v = y[i].v = 0;
        }

        sort(x, x+t, comp_r); 
        memset(vis, 0, sizeof(vis));
        bool possible = true;
        for (int i = 0; i < t and possible; ++i) {
            for (int j = x[i].l; j <= x[i].r; ++j) {
                if (vis[j])
                    continue;
                vis[j] = true;
                x[i].v = j;
                break;
            }
            possible = x[i].v;
        }

        sort(y, y+t, comp_r);
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < t and possible; ++i) {
            for (int j = y[i].l; j <= y[i].r; ++j) {
                if (vis[j])
                    continue;
                vis[j] = true;
                y[i].v = j;
                break;
            }
            possible = y[i].v;
        }

        if (!possible) {
            printf("IMPOSSIBLE\n");
        } else {
            sort(x, x+t, comp_idx);
            sort(y, y+t, comp_idx);
            for (int i = 0; i < t; ++i) {
                printf("%d %d\n", x[i].v, y[i].v);
            }
        }

    }


    return 0;
}
