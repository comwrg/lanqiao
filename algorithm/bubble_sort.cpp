// Written on 17/12/19
// bubble sort

#include <iostream>

using namespace std;

void show(int * arr, int left, int right) {
    for (int i = left; i <= right; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubble_sort(int * arr, int left, int right) {
    if (left >= right) {
        return;
    }
    for (int i = left; i < right; i++) {
        if (arr[i] > arr[i+1]) {
            swap(arr[i], arr[i+1]);
        }
    }

    bubble_sort(arr, left, right-1);
}

int main() {
    int arr[] = {-1, 2, 3, -2, 4, 7, 1, 1, 1};
    const int len = 9;
    bubble_sort(arr, 0, len-1);
    show(arr, 0, len-1);

    return 0;
}