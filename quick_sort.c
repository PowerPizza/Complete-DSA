#include <stdio.h>

int mr_partition(int arr[], int start, int end){
    int i = start+1;
    int j = end-1;
    while (j >= i){
        for (; j >= start; j--){
            if (arr[j] < arr[start] || j < i) {
                break;
            }
        }

        for (; i < end; i++){
            if (arr[i] > arr[start] || j <= i) {
                break;
            }
        }
        if (j > i){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }

        else if (j <= i){
            int temp = arr[j];
            arr[j] = arr[start];
            arr[start] = temp;
        }
    }

    return j;
}

int p = 0;
void printArr(int arr[], int arr_len);
void quickSort(int arr[], int start, int end){
    int pivot_idx = mr_partition(arr, start, end);
    if (start == end-1){
        return;
    }
    quickSort(arr, start, pivot_idx+1);  // checks left
    quickSort(arr, pivot_idx+1, end);  // checks right
}

void printArr(int arr[], int arr_len){
    for (int i = 0; i < arr_len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    // int arr[] = {22, 4, 12, 3, 1};
    // int arr[] = {1, 3, 2, 6, 4};
    // int arr[] = {5, 4, 3, 2, 1};
    // int arr[] = {2, 8, 7, 11, 6, 4, 15, 27, 5};

    // int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int arr[] = {5, 3, 8, 6, 2, 7, 4, 1, 9};
    // int arr[] = {4, 2, 4, 2, 4, 2, 4, 2};
    // int arr[] = {-3, -1, -7, -5, -2, -6, -4};
    int arr[] = {12, 45, 23, 67, 34, 89, 10, 24, 76, 58, 1, 9, 33, 47, 16, 82, 29, 60, 41, 3};
    // int arr[] = {1, 2, 3, 4, 5, 6, 8, 7, 9, 10};
    // int arr[] = {5, 1, 5, 2, 5, 3, 5, 4, 5, 0, 5, 6, 5, 7, 5, 8, 5, 9, 5};
    // int arr[] = {1, 2, 3, 10, 9, 8, 7, 4, 5, 6};

    int arr_size = sizeof(arr)/sizeof(int);
    printArr(arr, arr_size);
    quickSort(arr, 0, arr_size);
    printArr(arr, arr_size);
    return 0;
}