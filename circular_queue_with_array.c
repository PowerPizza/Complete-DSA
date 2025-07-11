#include <stdio.h>
#include <stdlib.h>

typedef struct circular_queue{
    int * data_arr;
    int start;
    int end;
    int size;
} CircularQueue;

int isFull(CircularQueue * queue){
    // O(1)
    if (queue->end - queue->start >= queue->size){
        return 1;
    }
    return 0;
}

int isEmpty(CircularQueue * queue){
    // O(1)
    if (queue->start == queue->end){
        return 1;
    }
    return 0;
}

void enqueue(CircularQueue * queue, int value){
    // O(1)
    if (isFull(queue)){
        printf("ERROR : ENQUEUE FAILD - QUEUE IS FULL\n");
        return;
    }
    int add_at = (queue->end + 1) %  queue->size;
    queue->data_arr[add_at] = value;
    queue->end += 1;
}

int dequeue(CircularQueue * queue){
    // O(1)
    if (isEmpty(queue)){
        printf("ERROR ; DEQUEUE FAILD - QUEUE IS EMPTY\n");
        return -1;
    }
    int delete_at = (queue->start + 1) % queue->size;
    int deleted_ele = queue->data_arr[delete_at];
    queue->start += 1;
    return deleted_ele;
}

void printQueue(CircularQueue * queue){
    /* O(n) in worse case,
    O(e-s) -> in worse case e-s = size of array = n */
    for (int i = queue->start; i < queue->end; i++){
        printf("%d\n", queue->data_arr[(i+1) % queue->size]);
    }
}

int main(){
    CircularQueue * cq1 = (CircularQueue*) malloc(sizeof(CircularQueue));
    cq1->size = 5;
    cq1->data_arr = (int*) malloc(sizeof(int)*cq1->size);
    cq1->start = cq1->end = -1;

    enqueue(cq1, 11);
    enqueue(cq1, 22);
    enqueue(cq1, 33);
    printf("DELETED %d\n", dequeue(cq1));
    enqueue(cq1, 44);
    enqueue(cq1, 55);
    enqueue(cq1, 66);
    printf("DELETED %d\n", dequeue(cq1));
    printf("DELETED %d\n", dequeue(cq1));
    enqueue(cq1, 77);
    enqueue(cq1, 88);
    printf("DELETED %d\n", dequeue(cq1));
    enqueue(cq1, 99);
    printf("DELETED %d\n", dequeue(cq1));
    printf("DELETED %d\n", dequeue(cq1));
    printf("DELETED %d\n", dequeue(cq1));
    enqueue(cq1, 111);
    enqueue(cq1, 222);
    enqueue(cq1, 333);
    enqueue(cq1, 444);
    printf("DELETED %d\n", dequeue(cq1));
    enqueue(cq1, 555);
    printf("DELETED %d\n", dequeue(cq1));
    printf("DELETED %d\n", dequeue(cq1));
    printf("DELETED %d\n", dequeue(cq1));
    enqueue(cq1, 312);

    printQueue(cq1);
    return 0;
}