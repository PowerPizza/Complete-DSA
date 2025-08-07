#include <stdio.h>
#include <stdlib.h>

void printArr(int * arr, int arr_len){
    for (int i = 0; i < arr_len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int findMax(int arr[], int arr_len){
    // O(n)
    int max = arr[0];
    for (int i = 0; i < arr_len; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int arr_len){
    // O(n) + 0(n) + O(m) = O(n + n + m) = O(2n + m) = O(n + m)
    if (!arr_len) return;

    int max = findMax(arr, arr_len);

    int * oxilary_arr = (int*) calloc(max+1, sizeof(int));  // calloc returns the array pointer from heap which has all value 0 by default.

    for (int i = 0; i < arr_len; i++){
        oxilary_arr[arr[i]] += 1;
    }

    int k = 0, j = 0;
    for (; j < max+1; j++){
        while (oxilary_arr[j] > 0){
            arr[k] = j;
            oxilary_arr[j] -= 1;
            k++;
        }
    }
    free(oxilary_arr);
}

int main(){
    int arr1[] = {3, 1, 9, 7, 1, 2, 4};  // not valid for -ve value containing arrays.
    int arr_size = sizeof(arr1)/sizeof(int);
    printArr(arr1, arr_size);
    countSort(arr1, arr_size);
    printArr(arr1, arr_size);
    return 0;
}