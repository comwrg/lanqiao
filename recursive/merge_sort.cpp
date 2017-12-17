// Written on 17/12/17
// merge sort

#include <iostream>

using namespace std;

// merge two sorted array.
void merge(int * arr, int left1, int right1, int left2, int right2) {
    int i = left1, j = left2;
    int len = right2 - left1 + 1;
    int temp[len];
    for (int x = 0; x < len; x++) {
        if (i <= right1 && j <= right2) {
            if (arr[i] > arr[j]) {
                temp[x] = arr[j++];
            } else {
                temp[x] = arr[i++];
            }
        } else if (i <= right1) {
            temp[x] = arr[i];
        } else if (j <= right2) {
            temp[x] = arr[j];
        } else {
            cout << "error";
        }
    }

    // copy to arr
    for (int x = 0; x < len; x++) {
        arr[left1+x] = temp[x];
    }
}

void merge_sort(int *arr, int left, int right) {
    // divide
    if (left >= right) {
        return;
    }
    int middle = (left + right) / 2;
    merge_sort(arr, left, middle);
    merge_sort(arr, middle + 1, right);
    cout << left     << "-"
         << middle   << " "
         << middle+1 << "-"
         << right    << " "
         << endl;
    merge(arr, left, middle, middle+1, right);
}

int main() {
    int arr[] = {3, 7, 0, 2, -1, 1, 6};
    merge_sort(arr, 0, 6);
    for (int i : arr) {
        cout << i << " ";
    }
    return 0;
}

