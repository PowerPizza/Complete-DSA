#include <stdio.h>

void printArr(int arr[], int arr_len){
    for (int i = 0; i < arr_len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Method 1
int partition(int arr[], int start, int end){
    // in best case -> pivot is always moved at centre -> O(logn)
    // in worse case -> O(n)
    int pivot = arr[start];
    int i = start+1;
    int j = end;
    do {
        while (arr[i] <= pivot){
            i++;
        }

        while (arr[j] > pivot){
            j--;
        }
        
        if (i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    
    arr[start] = arr[j];
    arr[j] = pivot;

    return j;
}

void quickSort(int arr[], int start, int end){
    if (start >= end) return;
    // worst case : partition runs in O(n) and quickSort runs in O(n) -> O(n)*O(n) = O(n^2)
    // best case : partition runs in O(n) and quickSort runs in O(logn) -> O(n)*O(logn) = O(nlogn)
    printf("called\n");
    int pivot_idx = partition(arr, start, end);
    quickSort(arr, start, pivot_idx-1); // left side
    quickSort(arr, pivot_idx+1, end); //  right side
}

// METHOD 2
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

void quickSort2(int arr[], int start, int end){
    int pivot_idx = mr_partition(arr, start, end);
    if (start == end-1){
        return;
    }
    quickSort2(arr, start, pivot_idx+1);  // checks left
    quickSort2(arr, pivot_idx+1, end);  // checks right
}



int main(){
    // int arr[] = {22, 4, 12, 3, 1};
    // int arr[] = {1, 2, 3, 4, 5};
    int arr[] = {5, 4, 3, 2, 1};
    // int arr[] = {2, 8, 7, 11, 6, 4, 15, 27, 5};

    // int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int arr[] = {5, 3, 8, 6, 2, 7, 4, 1, 9};
    // int arr[] = {4, 2, 4, 2, 4, 2, 4, 2};
    // int arr[] = {-3, -1, -7, -5, -2, -6, -4};
    // int arr[] = {12, 45, 23, 67, 34, 89, 10, 24, 76, 58, 1, 9, 33, 47, 16, 82, 29, 60, 41, 3};
    // int arr[] = {1, 2, 3, 4, 5, 6, 8, 7, 9, 10};
    // int arr[] = {5, 1, 5, 2, 5, 3, 5, 4, 5, 0, 5, 6, 5, 7, 5, 8, 5, 9, 5};
    // int arr[] = {1, 2, 3, 10, 9, 8, 7, 4, 5, 6};

    int arr_size = sizeof(arr)/sizeof(int);
    printArr(arr, arr_size);
    // quickSort2(arr, 0, arr_size);
    quickSort(arr, 0, arr_size-1);
    printArr(arr, arr_size);
    return 0;
}