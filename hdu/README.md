# hdu thinking
http://acm.hdu.edu.cn/typeclass.php

## 1003
this question i didn't expect to do with dp. <br/>
firstly, i use sum(i) - min(sum(0)->sum(i)), but it's not effect.

then i searched answer code, i can't understand why state transition equation is
`dp(n) = max(dp(n)+data(n), data(n))`.
later, i reaziled that i forgot nature of dp is optimal substructure.

# 1005
https://blog.csdn.net/hurmishine/article/details/51333005

## 1007 (最近点对)

## 1009 (greedy)

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

## 1114 (完全背包)
一开始看代码跟01背包比较就for循环的顺序不一样 感觉好奇怪 不是很能理解，
然后手动模拟了一下 突然发现好神奇

https://freesouls.github.io/2016/02/27/backpack-problem-II/
个人觉得这个讲得非常好 循序渐进

## [1243](#head)
dp 用 `递归` 写就Timeout， 用 `迭代` 写就AC。
不清楚是什么情况？搞得以后都不敢用`递归`了。

## 1520 (树状dp)

## 1712 (分组背包)
分组背包 在网上搜的千篇一律的都是用的优化过的一维数组， 3个for循环，估计是自己太垃圾了。对于没接触过的我来说， 很不好理解。
自己按照状态转移方程写了一个递归版的， 应该先理解递归版的， 再去优化， 这样会更加好理解。

## 2159 (二维完全背包)
这题网上有3个for循环的， 个人觉得不好理解， 没有完全背包的感觉，有01背包的感觉。
我自己按照自己的思路写了个， AC了，速度也比3个for循环快很多

## 2191 (多重背包)
二进制优化讲解 https://blog.csdn.net/jkay_wong/article/details/7240588

这个是看背包九讲上写的， 思考好久关于01背包的部分， 为什么要这么调用01背包。
看背包九讲上自己理解的迷迷糊糊的， 知道是二进制分解， 但是不知道为什么要那么写。
后来明白了， 假如有n个物品， 按照正常思路应该这么写， 就是没优化之前
```c++
for (int i = 0; i < n; ++i) {
    pack_zero_one(cost, value);
}
```
这样， 每次调用n次01背包， 这样时间复杂度是n

然后， 用二进制优化， 就是说每次可以买1, 2, 4, 8 ... 件物品 <br>
比如 <br>
第一次， 在买 1 件物品 和 买 0 件 物品 中取最优解 <br>
第二次， 在买 2 件物品 和 买 0 件 物品 中取最优解 <br>
第三次， 在买 4 件物品 和 买 0 件 物品 中取最优解 <br>
... <br>
最后一次， 在 买 最后剩余的物品 和 买 0 件 物品 中取最优解 <br>

这样， 就可以组成 0 到 n 中任意一个数字

如果还不理解， 比如 10 可以用二进制 分解为 <br>
10 = 1 + 2 + 4 + 3 <br>
那么 假如 买9件商品 是最优解的话， 可以分别买 2 + 4 + 3 件 <br>
假如 8 件是最优解， 可以分别买 1 + 4 + 3 件 这样 <br>
... 同理 <br>
恩， 这是我思考好久的.... 网络上搜的文章没有讲的很清楚的， 都是一带而过。


## 2602 (01背包)

