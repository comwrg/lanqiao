#include <iostream>

using namespace std;

int main() {
    int month, day, hour, min, sec;
    int pastSec;

    month = 1; day = 16; hour = 23; min = 59; sec = 59;
    pastSec = 1;

    scanf("2018-%d-%d %d:%d:%d", &month, &day, &hour, &min, &sec);
    scanf("%d", &pastSec);

    sec += pastSec;
    min += sec / 60;
    hour += min / 60;
    int pastDay = hour / 24;

    cout << pastDay;

    return 0;
}