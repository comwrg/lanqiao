// Written on 17/12/19
// cocktail shaker sort (variant from bubble sort)

#include <iostream>

using namespace std;

void show(int * arr, int left, int right) {
    for (int i = left; i <= right; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void cocktail_shaker_sort(int * arr, int left, int right) {
    if (left >= right) {
        return;
    }
    for (int i = left; i < right; i++) {
        if (arr[i] > arr[i+1]) {
            swap(arr[i], arr[i+1]);
        }
    }
    for (int i = right-1; i > left; i--) {
        if (arr[i-1] > arr[i]) {
            swap(arr[i-1], arr[i]);
        }
    }
    cocktail_shaker_sort(arr, left+1, right-1);
}

int main() {
    int arr[] = {-1, 2, 3, -2, 4, 7, 1, 1, 1};
    const int len = 9;
    cocktail_shaker_sort(arr, 0, len-1);
    show(arr, 0, len-1);

    return 0;
}