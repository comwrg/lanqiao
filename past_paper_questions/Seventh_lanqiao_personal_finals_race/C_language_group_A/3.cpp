/**
 *
 * 打靶
 *
 * 小明参加X星球的打靶比赛。
 * 比赛使用电子感应计分系统。其中有一局，小明得了96分。
 *
 * 这局小明共打了6发子弹，没有脱靶。
 * 但望远镜看过去，只有3个弹孔。
 * 显然，有些子弹准确地穿过了前边的弹孔。
 *
 * 不同环数得分是这样设置的：
 * 1,2,3,5,10,20,25,50
 *
 * 那么小明的6发子弹得分都是多少呢？有哪些可能情况呢？
 *
 * 下面的程序解决了这个问题。
 * 仔细阅读分析代码，填写划线部分缺失的内容。
 */


#include <stdio.h>

#define N 8

void f(int ta[], int da[], int k, int ho, int bu, int sc) {
    int i, j;
    if (ho < 0 || bu < 0 || sc < 0)
        return;
    if (k == N) {
        if (ho > 0 || bu > 0 || sc > 0)
            return;
        for (i = 0; i < N; i++) {
            for (j = 0; j < da[i]; j++)
                printf("%d ", ta[i]);
        }
        printf("\n");
        return;
    }

    for (i = 0; i <= bu; i++) {
        da[k] = i;
        // f(ta, da, k + 1, _____________, bu - i, sc - ta[k] * i);  //填空位置
        f(ta, da, k+1, ho - (i > 0), bu-i, sc - ta[k]*i);
    }

    da[k] = 0;
}

int main() {
    int ta[] = {1, 2, 3, 5, 10, 20, 25, 50};
    int da[N];
    f(ta, da, 0, 3, 6, 96);
    return 0;
}

/**
注意：只填写划线处缺少的内容，不要填写已有的代码或符号，也不要填写任何解释说明文字等。
 */