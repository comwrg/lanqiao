// Written on 17/12/18
// quick sort
#include <iostream>

using namespace std;

void show(int * arr, int left, int right) {
    for (int i = left; i <= right; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void quick_sort(int * arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = arr[left];
    int i = left, j = right;
    while (i <= j) {
        bool is_break = false;
        while (arr[i] < pivot && !is_break) {
            i++;
            is_break = (i > j);
        }
        while (arr[j] > pivot && !is_break) {
            j--;
            is_break = (i > j);
        }

        if (is_break)
            break;

        // swap arr[i] and arr[j]
        int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        i++; j--;
    }
    if (i == j) {
        j--;
        i++;
    }
    quick_sort(arr, left, j);
    quick_sort(arr, i, right);
}

int main() {
    int arr[] = {-1, 2, 3, -2, 4, 7, 1, 1, 1};
    const int len = 9;
    quick_sort(arr, 0, len-1);
    show(arr, 0, len-1);

    return 0;
}
