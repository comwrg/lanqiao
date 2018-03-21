// Written on 17/12/19
// insertion sort

#include <iostream>

using namespace std;

void show(int * arr, int left, int right) {
    for (int i = left; i <= right; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int find_insert_index(const int * arr, int right, int value) {
    for (int i = right; i >= 0; i--) {
        if (value >= arr[i]) {
            return i+1;
        }
    }
    return 0;
}

int move_to_next(int * arr, int begin, int end) {
    for (int i = end; i >= begin; i--) {
        arr[i+1] = arr[i];
    }
}

void insertion_sort(int * arr, int middle, int right) {
    if (middle > right) {
        return;
    }
    int insert_value = arr[middle+1];
    int index = find_insert_index(arr, middle, insert_value);
    move_to_next(arr, index, middle);
    arr[index] = insert_value;
    insertion_sort(arr, middle+1, right);
}

int main() {
    int arr[] = {-1, 2, 3, -2, 4, 7, 1, 1, 1};
    const int len = 9;
    insertion_sort(arr, 0, len-1);
    show(arr, 0, len-1);
    return 0;
}
