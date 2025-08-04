#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int arr_size){
    for (int i = 0; i < arr_size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int * mergeAndSortTwoArrays(int * s_arr1, int size_arr1, int * s_arr2, int size_arr2){
    int * new_arr = (int*) malloc((size_arr1+size_arr2)*sizeof(int));

    int i, j, k;
    i = j = k = 0;
    while (j < size_arr2 && i < size_arr1)
    {
        if (s_arr1[i] > s_arr2[j]){
            new_arr[k] = s_arr2[j];
            k++;
            j++;
        }
        else{
            new_arr[k] = s_arr1[i];
            k++;
            i++;
        }
    }
    for (; i < size_arr1; i++){
        new_arr[k] = s_arr1[i];
        k++;
    }
    for (; j < size_arr2; j++){
        new_arr[k] = s_arr2[j];
        k++;
    }
    return new_arr;
}

int main(){
    // int arr1[] = {1, 4, 12, 22, 44, 55};
    int arr1[] = {7, 9, 18, 19, 22};
    int size1 = sizeof(arr1)/sizeof(int);
    // int arr2[] = {11, 18, 39, 48};
    int arr2[] = {1, 6, 9, 11};
    int size2 = sizeof(arr2)/sizeof(int);
    int * new_ = mergeAndSortTwoArrays(arr1, size1, arr2, size2);
    printArr(new_, size1+size2);
    return 0;
}