#include <stdio.h>
#include <stdlib.h>

typedef struct arrayADT {
    int totalSize;
    int usedSize;
    int * arr;
} ArrayADT;

ArrayADT * intiArrayADT(int Tsize){
    // Time complexity O(1)
    ArrayADT * a1 = (ArrayADT*) malloc(sizeof(ArrayADT));
    a1->totalSize = Tsize;
    a1->usedSize = 0;
    a1->arr = (int*) malloc(Tsize*sizeof(int));
    return a1;
}

void append(ArrayADT * a1, int data) {
    // Time complexity O(1)
    if (a1->usedSize == a1->totalSize){
        printf("Appending Error : array index out of range");
        return;
    }
    a1->arr[a1->usedSize] = data;
    a1->usedSize += 1;
}

void insert_MO(ArrayADT * a1, int index, int data) { // MO -> Maintain Order
    // Time complexity | Best case -> O(1)   insertion at last index
    // Time complexity | Worst case -> O(n)   insertion at first index
    for (int i = a1->usedSize; i > index; i--){
        a1->arr[i] = a1->arr[i-1];
    }
    a1->arr[index] = data;
    a1->usedSize++;
}

void insert_NMO(ArrayADT * a1, int index, int data) { // NMO -> Maintain Order
    // Time complexity O(1)
    a1->arr[a1->usedSize] = a1->arr[index];
    a1->arr[index] = data;
    a1->usedSize++;
}

int delete_MO(ArrayADT * a1, int index){
    // Time complexity | Best case -> O(1)   deletion at last index
    // Time complexity | Worst case -> O(n)   deletion at first index
    int to_delete = a1->arr[index];
    for (int i = index; i < a1->usedSize-1; i++){
        a1->arr[i] = a1->arr[i+1];
    }
    a1->usedSize--;
    return to_delete;
}

int delete_NMO(ArrayADT * a1, int index){
    // Time complexity O(1)
    int to_delete = a1->arr[index];
    a1->usedSize--;
    a1->arr[index] = a1->arr[a1->usedSize];
}

int linearSearch(ArrayADT * a1, int element){
    // Time complexity | Best case - O(1) when element found at first index.
    // Time complexity | Worst case - O(n) when element found at last index or not found.
    for (int i = 0; i < a1->usedSize; i++){
        if (a1->arr[i] == element){
            return 1;
        }
    }
    return -1;
}

int binarySearch(ArrayADT * a1, int element){
    // Time complexity | Best case - O(1)   if element found at 1st, middle or last position.
    // Time complexity | Worst case - O(logN) if element is not found at first, mid or last position or is not present.
    int low = 0;
    int high = a1->usedSize-1;
    int mid = (high + low)/2;
    
    while (mid > 3) {
        if (a1->arr[low] == element || a1->arr[high] == element || a1->arr[mid] == element){
            return 1;
        }
        else if (element > a1->arr[mid]){
            low = mid;
            mid = (low + high)/2;
        }
        else if (element < a1->arr[mid]){
            high = mid;
            mid = (low + high)/2;
        }
    }
    return -1;
}

void printArrayADT(ArrayADT * a1){
    // Time complexity O(n)
    for (int i = 0; i < a1->usedSize; i++){
        printf("%d, ", a1->arr[i]);
    }
    printf("\n");
}

int main() {
    ArrayADT * my_arr = intiArrayADT(10);
    append(my_arr, 20);
    append(my_arr, 30);
    append(my_arr, 40);
    append(my_arr, 60);
    printArrayADT(my_arr);

    insert_MO(my_arr, 4, 100);
    printArrayADT(my_arr);

    insert_NMO(my_arr, 2, 2000);
    printArrayADT(my_arr);

    delete_MO(my_arr, 5);
    printArrayADT(my_arr);

    delete_NMO(my_arr, 0);
    printArrayADT(my_arr);
    
    printf("Element search result by linear search : %d\n", linearSearch(my_arr, 20020));

    ArrayADT * my_arr2 = intiArrayADT(12);
    append(my_arr2, 20);
    append(my_arr2, 23);
    append(my_arr2, 25);
    append(my_arr2, 26);
    append(my_arr2, 29);
    append(my_arr2, 33);
    append(my_arr2, 36);
    append(my_arr2, 45);
    printArrayADT(my_arr2);
    printf("Element search result by binary search : %d\n", binarySearch(my_arr2, 234322));
    return 0;
}
