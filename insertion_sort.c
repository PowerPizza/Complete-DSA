#include <stdio.h>

void printArray(int arr[], int arr_size){
    for (int i = 0; i < arr_size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int arr_len){
    for (int i = 1; i < arr_len; i++){
        int check_for = arr[i];
        for (int j = i-1; j >= 0; j--){
            if (check_for < arr[j]){
                int old = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = old;
            }
            else{
                break;
            }
        }
    }
}

void insertionSort2(int * arr, int arr_len) {
    for (int i = 1; i < arr_len; i++){
        int to_compare = arr[i];
        int j = i-1;
        while (j >= 0 && to_compare < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = to_compare;
    }
}

int main(){
    // int arr[] = {1776, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    // int arr[] = {1, 12, 3, 14, 15, 17, 16};
    int arr[] = { 42, 17, 93, 58, 21, 73, 14, 67, 88, 5, 39, 27, 91, 33, 61, 55, 49, 12, 84, 3, 78, 66, 25, 10, 99, 8, 41, 18, 90, 60};
    int arr_size = sizeof(arr)/sizeof(int);
    // insertionSort(arr, arr_size);

    insertionSort2(arr, arr_size);
    printArray(arr, arr_size);

    return 0;
}