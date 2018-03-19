# Day1
## Question 3
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
