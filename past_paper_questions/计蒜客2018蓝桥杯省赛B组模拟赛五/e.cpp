#include <iostream>
using namespace std;
int main() {
    int n, ans = 0;
    n = 140;
    while (n) {
        ans += 0;int m=n--,i=0; while(m%5==0) {m/=5; i++;}; ans += i;
    }
    cout << ans << endl;
    return 0;
}
/*
def zero(n):
    sum = 1
    for i in range(1, n+1):
        sum *= i
    sum = str(sum)
    print(n,  end=' ')
    i = -1
    while sum[i] == '0':
        i -= 1
    return abs(i+1)

print(zero(10000))
# 5, 10, 15, 20, 25, 30, 35, 40,
 */