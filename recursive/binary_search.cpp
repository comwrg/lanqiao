// Written on 17/12/03.
// Find a value with binary search.
#include <iostream>

using namespace std;

int find(const int * arr, int key, int begin, int end) {
//    cout << "begin: " << begin << " end: " << end << endl;
    int pos = (begin + end) / 2;
    int n = arr[pos];
    if (key == n) {
        return pos;
    } else if (key > n) {
        return find(arr, key, pos + 1, end);
    } else {
        return find(arr, key, begin, pos - 1);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int pos = find(arr, 3, 0, 7);
    cout << pos << endl;
    return 0;
}
