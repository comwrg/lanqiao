// Written on 17/12/03.
// Recursive search max value in array.
#include <iostream>

int max(int a, int b) {
    return a > b ? a : b;
}

int find_max(const int * arr, int len, int pos) {
    if (pos == len - 1) {
        return arr[pos];
    } else {
        return max(arr[pos], find_max(arr, len, pos + 1));
    }
}

int main() {
    int arr[] = {1, -1, 3, 4, -3, 10, 32};
    int max = find_max(arr, 7, 0);
    std::cout << max << std::endl;
    return 0;
}