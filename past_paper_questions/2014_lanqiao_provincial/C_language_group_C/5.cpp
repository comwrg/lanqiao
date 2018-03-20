/**
串逐位和

给定一个由数字组成的字符串，我们希望得到它的各个数位的和。
比如：“368” 的诸位和是：17
这本来很容易，但为了充分发挥计算机多核的优势，小明设计了如下的方案：
 */
#include "stdio.h"
#include "string.h"
int f(char s[], int begin, int end)
{
    int mid;
    if(end-begin==1) return s[begin] - '0';
    mid = (end+begin) / 2;
    //return ____________________________________;  //填空
    return f(s, begin, mid) + f(s, mid, end);
}

int main()
{
    char s[] = "4725873285783245723";
    printf("%d\n",f(s,0,strlen(s)));
    return 0;
}

/**
你能读懂他的思路吗？ 请填写划线部分缺失的代码。

注意：只填写缺少的部分，不要填写已有代码或任何多余内容。
 */