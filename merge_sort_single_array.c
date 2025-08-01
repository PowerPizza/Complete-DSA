#include <stdio.h>

void printArr(int arr[], int arr_size){
    for (int i = 0; i < arr_size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void mergeSortedArrays(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid+1;
    int k = 0;

    int new_arr[high - low];

    while (i <= mid && j < high) {
        if (arr[i] > arr[j]){
            new_arr[k] = arr[j];
            k++;
            j++;
        }
        else{
            new_arr[k] = arr[i];
            k++;
            i++;
        }
    }

    for (; i <= mid; i++){
        new_arr[k] = arr[i];
        k++;
    }
    for (; j < high; j++){
        new_arr[k] = arr[j];
        k++;
    }

    int h = 0;
    for (h = 0, i = low; i < high; i++, h++){
        arr[i] = new_arr[h];
    }
}

void mergeSort(int arr[], int l, int h){
    if (h - l < 2) return;

    int mid = (l + h)/2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid, h);

    mergeSortedArrays(arr, l, mid-1, h);
}

int main(){
    // int arr1[] = {7, 15, 2, 8, 10};
    // int arr1[] = {1, 8, 3, 4, 12, 2, 14};
    // int arr1[] = {12, 2, 7, 21, 27, 15, 25, 4, 8};
    int arr1[] = {-2147483648, 2147483647, 0, -1, 1};
    int arr_len = sizeof(arr1)/sizeof(int);
    printArr(arr1, arr_len);
    mergeSort(arr1, 0, arr_len);
    printArr(arr1, arr_len);
    return 0;
}