#include <stdio.h>
#include <stdlib.h>

typedef struct que{
    int * data_arr;
    int start;
    int end;
    int size;
} Queue;

int isEmpty(Queue * queue){
    // O(1)
    if (queue->start == queue->end){
        return 1;
    }
    return 0;
}

int isFull(Queue * queue){
    // O(1)
    if (queue->end == queue->size-1){
        return 1;
    }
    return 0;
}

void enqueue(Queue * queue, int data){
    // O(1)
    if (isFull(queue)){
        return;
    }
    queue->end++;
    queue->data_arr[queue->end] = data;
}

void dequeue(Queue * queue){
    // o(1)
    if (isEmpty(queue)){
        return;
    }
    queue->start++;
}

void printQueue(Queue * queue){
    // O(n)
    for (int i = queue->start; i < queue->end; i++){
        printf("%d\n", queue->data_arr[i+1]);
    }
}

int peek(Queue * queue, int index){
    // O(1)
    return queue->data_arr[queue->start + 1 + index];
}

int firstVal(Queue * queue){
    // O(1)
    return queue->data_arr[queue->start+1];
}

int lastVal(Queue * queue){
    // O(1)
    return queue->data_arr[queue->end];
}

int main(int argc, char const *argv[])
{
    Queue * queue1 = (Queue*) malloc(sizeof(Queue));
    queue1->size = 10;
    queue1->data_arr = (int*) malloc(sizeof(int)*queue1->size);
    queue1->start = -1;
    queue1->end = -1;

    enqueue(queue1, 100);
    enqueue(queue1, 500);
    enqueue(queue1, 600);
    enqueue(queue1, 700);

    dequeue(queue1);
    dequeue(queue1);

    printQueue(queue1);

    printf("Value at index 0 : %d\n", peek(queue1, 0));
    printf("First Value : %d\n", firstVal(queue1));
    printf("Last Value : %d\n", lastVal(queue1));
    return 0;
}
