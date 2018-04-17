# hdu thinking

## 1003
this question i didn't expect to do with dp. <br/>
firstly, i use sum(i) - min(sum(0)->sum(i)), but it's not effect.

then i searched answer code, i can't understand why state transition equation is
`dp(n) = max(dp(n)+data(n), data(n))`.
later, i reaziled that i forgot nature of dp is optimal substructure.

# 1005
https://blog.csdn.net/hurmishine/article/details/51333005

# 1006
find reason why not simulate
http://acm.hdu.edu.cn/discuss/problem/post/reply.php?postid=9537&messageid=2&deep=1

idea
http://www.voidcn.com/article/p-dgpefnqe-zu.html

## 1016
这题耗费很长时间在一个莫名其妙的Bug上
应该是OJ上的Bug， 用的OJ是 http://acm.hdu.edu.cn/
具体是
`data` 和 `mark` 数组 用 动态分配 的方式 创建 会不通过
```c++
int data[20];
int mark[20];
```
改为
```c++
int *data;
int *mark;

int main() {
    // ...
    data = new data[20];
    mark = new mark[20];
    // ...
    return 0;
}
```
emm..

## 1072
为什么可以用dfs找到一定是最短路径？我迷惑了很久
后来发现dfs是所有分支一起走， 所以路径长度是一起增加的，
所以说最先找到的路径一定比后面找到的路径短。

## [1243](#head)
dp 用 `递归` 写就Timeout， 用 `迭代` 写就AC。
不清楚是什么情况？搞得以后都不敢用`递归`了。
