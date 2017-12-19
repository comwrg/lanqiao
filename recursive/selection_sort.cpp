// Written on 17/12/19
// selection sort

#include<iostream>

using namespace std;

void show(int * arr, int left, int right) {
    for (int i = left; i <= right; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selection_sort(int * arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int min_index = left;
    for (int i = left+1; i <= right; i++) {
        if (arr[i] < arr[min_index]) {
            min_index = i;
        }
    }
    // swap arr[left] and arr[min_index]
    int temp = arr[left]; arr[left] = arr[min_index]; arr[min_index] = temp;
    selection_sort(arr, left+1, right);
}

int main() {
    int arr[] = {1, -1, 3, 4, -3, 10, 32, 1, 2, 1, 1};
    const int len = 11;
    selection_sort(arr, 0, len-1);
    show(arr, 0, len-1);

    return 0;
}