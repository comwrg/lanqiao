#include <iostream>
#include <cstring>
using namespace std;
const int N = 100;

int olds, news;
char olddata[N], newdata[N];

void swit() {
    long long n = 0, flag = 1;
    for (int i = 0; olddata[i]; ++i) {
        if (olddata[i] == '-') {
            flag = -1;
        }
        else if(olddata[i] > '9') {
            n = n * olds + olddata[i] - 55;
        }
        else {
            n = n * olds + olddata[i] - '0';
        }
    }
    n *= flag;
    string s;
    int tmp = 0;
    while(n != 0) {
        tmp = n % news;
        n /= news;
        if (tmp >= 10) {
            s = char(tmp + 55) + s;
        }
        else {
            /*在这里填写必要的代码*/
            s = char(tmp + '0') + s;
        }
    }
    for (int i = 0; s[i]; ++i) {
        newdata[i] = s[i];
    }
}

int main() {
//    cin >> olds >> news;
//    cin >> olddata;
    olds = 36, news = 2;
    olddata[0] = 'Z', olddata[1] = '\0';
    swit();
    cout << newdata << endl;
    return 0;
}