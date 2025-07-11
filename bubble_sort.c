#include <stdio.h>

void bubble_sort(int arr[], int arr_len){
    // Time complexity : BEST CASE -> O(n)
    // Time complexity : WORST CASE -> O(n^2)
    // ITS CONFIGURED FOR ADAPTIVE ALGORITHM - If provided array is already sorted so it takes O(n) time even in worse case.
    for (int i = 0; i < arr_len-1; i++){
        // int comp = 0;
        int swap = 0;
        for (int j = 0; j < arr_len - 1 - i; j++){
            if (arr[j] > arr[j+1]){
                int jth = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = jth;
                swap++;
            }
            // comp++;
        }
        if (swap == 0){
            return;
        }
        // printf("%d comarisions and %d swaps\n", comp, swap);
    }
}

int main(){
    // int arr[] = {2, 3, 1, 5, 44, 75, 34, 23};
    // int arr[] = {7, 11, 9, 2, 17, 4};
    // int arr[] = {2, 4, 7, 9, 11, 17};
    int arr[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    bubble_sort(arr, sizeof(arr)/sizeof(int));
    for (int k = 0; k < sizeof(arr)/sizeof(int); k++){
        printf("%d ", arr[k]);
    }
    printf("\n");
    return 0;
}