# algorithm

## 扩展欧几里德算法
用途是可以计算出二元一次不定方程 `ax + by = gcd(a,b)` 中的整数解 <br>
先要理解[wiki](https://zh.wikipedia.org/wiki/%E6%89%A9%E5%B1%95%E6%AC%A7%E5%87%A0%E9%87%8C%E5%BE%97%E7%AE%97%E6%B3%95)中的例子， 手动是怎么算的， 然后再用程序实现。<br>
现在我也不懂程序要怎么写，虽然有现成别人写好的， 但是不自己亲自推导一遍是很难理解的，
所以现在打算自己推导一遍 <br>
先从gcd这个最基础的函数开始加功能。
```c++
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
```

要返回两个整数所以参数加上 &x, &y
```c++
int gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
```

看了一会， 感觉要推导出还是有点难度的 <br>
wiki上的例子
<pre>
47 = 30 * 1 + 17
30 = 17 * 1 + 13
17 = 13 * 1 + 4
13 = 4  * 3 + 1
</pre>
按照wiki上来， a = 47， b = 30
上面的式子不就是 `a = b * (a/b) + a%b` 这样吗
这样输出一波
```c++
int gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        return a;
    }
    printf("%d = %d * %d + %d\n", a, b, a/b, a%b);
    int r = gcd(b, a % b, x, y);
    return r;
}

int main() {
    int x, y;
    gcd(47, 30, x, y);
    return 0;
}
```
输出结果
<pre>
47 = 30 * 1 + 17
30 = 17 * 1 + 13
17 = 13 * 1 + 4
13 = 4 * 3 + 1
4 = 1 * 4 + 0
</pre>
然后按照wiki上的是改写成“余数等于”的形式
<pre>
17 = 47 * 1 + 30 * (-1)
...
</pre>
那不就是 `a%b = a * 1 + b * (-a/b)` <br>
再次输出一波
```c++
int gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        return a;
    }
    printf("%d = %d * 1 + %d * (-%d)\n", a%b, a, b, a/b);
    int r = gcd(b, a % b, x, y);
    return r;
}

int main() {
    int x, y;
    gcd(47, 30, x, y);
    return 0;
}
```
输出
<pre>
17 = 47 * 1 + 30 * (-1)
13 = 30 * 1 + 17 * (-1)
4 = 17 * 1 + 13 * (-1)
1 = 13 * 1 + 4 * (-3)
0 = 4 * 1 + 1 * (-4)
</pre>
然后， 依次把倒数第二项代入到最后一项
```c++
int gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        return a;
    }
    int r = gcd(b, a % b, x, y);
    if (a%b == 1) {
        x = 1;
        y = -a/b;
    }
    printf("%d = %d * 1 + %d * (-%d)\n", a%b, a, b, a/b);
    printf("prev x=%d, y=%d, now x=%d, y=%d\n", x, y, 1, -a/b);
    x = 1;
    y = -a/b;
    return r;
}

int main() {
    int x, y;
    gcd(47, 30, x, y);
    return 0;
}
```
然后这样输出一下， 看下顺序
然后， 为了方便区别x，y是传进来的， 还是当前的我定义了
pre_x, pre_y, now_x, now_y, 4个变量，
根据wiki上的带入， 我推到出一下公式
<pre>
x = now_x * pre_y
y = pre_x + now_y + pre_y
</pre>
<pre>
比如
1 = 13 * 1 + 4 * (-3)  // 1式
4 = 17 * 1 + 13 * (-1) // 2式

1式肯定比二式先算出来

1 = 13 * 1 + 4 * (-3)  // 1式
         ~       ~~~~
       pre_x=1   pre_y=-3
4 = 17 * 1 + 13 * (-1) // 2式
         ~        ~~~~
       now_x=1    now_y=1
这里的pre是对于2式来说的

带入
1 = 13 * 1 + [17 * 1 + 13 * (-1)] * (-3)
         ~         ~        ~~~~    ~~~~
        pre_x     now_x     now_y   pre_y
然后合并， 就可以得出式子
</pre>
于是可以写下如下代码, 还有个问题就是为什么 b==0 的时候 要初始化x=0, y=1呢
还是上面那个式子， 就是说没有pre_x, pre_y的时候， 要让 x = now_x, y = now_y,
这样就可以推到出初始化的值。
```c++
int gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 0;
        y = 1;
        return a;
    }
    int r = gcd(b, a % b, x, y);
    if (a%b) {
        int pre_x = x, pre_y = y;
        int now_x = 1, now_y = -a/b;
        x = now_x * pre_y;
        y = pre_x + now_y * pre_y;
        printf("%d = %d * 1 + %d * (-%d)\n", a%b, a, b, a/b);
        printf("prev x=%d, y=%d, now x=%d, y=%d, result --> x=%d, y=%d\n", pre_x, pre_y, now_x, now_y, x, y);
    }
    return r;
}

int main() {
    int x, y;
    gcd(47, 30, x, y);
    printf("x=%d, y=%d\n", x, y);
    return 0;
}
```
输出
<pre>
1 = 13 * 1 + 4 * (-3)
prev x=0, y=1, now x=1, y=-3, result --> x=1, y=-3
4 = 17 * 1 + 13 * (-1)
prev x=1, y=-3, now x=1, y=-1, result --> x=-3, y=4
13 = 30 * 1 + 17 * (-1)
prev x=-3, y=4, now x=1, y=-1, result --> x=4, y=-7
17 = 47 * 1 + 30 * (-1)
prev x=4, y=-7, now x=1, y=-1, result --> x=-7, y=11
x=-7, y=11
</pre>
接下来的事情就是简化代码
去掉了 a%b 的判断条件
为什么初始化变成了x=1， y=0
因为最后总会多出一项 是 0 = ...
所以 要让 算出来的 x = 0， 算出来的 y = 1
还是一样， 根据上面的式子推到出
```c++
int gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = gcd(b, a % b, x, y);
    int pre_x = x, pre_y = y;
    int now_x = 1, now_y = -a/b;
    x = now_x * pre_y;
    y = pre_x + now_y * pre_y;
    printf("%d = %d * 1 + %d * (-%d)\n", a%b, a, b, a/b);
    printf("prev x=%d, y=%d, now x=%d, y=%d, result --> x=%d, y=%d\n", pre_x, pre_y, now_x, now_y, x, y);
    return r;
}

int main() {
    int x, y;
    gcd(47, 30, x, y);
    printf("x=%d, y=%d\n", x, y);
    return 0;
}
```
最后优化后的代码
```c++
int gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int r = gcd(b, a % b, y, x);
    y -= a/b * x;
    return r;
}

int main() {
    int x, y;
    gcd(47, 30, x, y);
    printf("x=%d, y=%d\n", x, y);
    return 0;
}
```
