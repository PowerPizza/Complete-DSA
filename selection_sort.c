#include <stdio.h>

void selectionSort(int * arr, int arr_len){
    // Time complexity => Best Case = Worst Case = O(n^2)
    for (int i = 0; i < arr_len - 1; i++){
        int min_idx = i;
        for (int j = i+1; j < arr_len; j++){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void printArr(int * arr, int arr_len){
    for (int i = 0; i < arr_len; i++){
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int main(){
    // int arr[] = {10, 12, 3, 2, 78, 56, 67, 88, 97, 42};
    int arr[] = {7, 6, 5, 4, 3, 2, 1};
    int arr_size = sizeof(arr) / sizeof(int);
    printArr(arr, arr_size);
    selectionSort(arr, arr_size);
    printArr(arr, arr_size);
    return 0;
}