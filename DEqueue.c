#include <stdio.h>
#include <stdlib.h>

typedef struct de_queue{
    int * data_arr;
    int front;
    int rear;
    int size;
} DEQueue;

DEQueue * initDeQueue(int size){
    DEQueue * dq = (DEQueue*) malloc(sizeof(DEQueue));
    dq->data_arr = (int *) malloc(sizeof(int)*size);
    dq->size = size;
    dq->front = dq->rear = -1;
    return dq;
}

int isFull(DEQueue * q){
    if (q->rear == q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(DEQueue * q){
    if (q->rear == q->front){
        return 1;
    }
    return 0;
}

void enqueueRear(DEQueue * q, int data){
    if (isFull(q)) {
        return;
    }
    q->rear++;
    q->data_arr[q->rear] = data;
}

void enqueueFront(DEQueue * q, int data){
    if (q->front == -1){  // also isFull condition but for front side, can't be merged with isFull()
        return;
    }
    q->data_arr[q->front] = data;
    q->front--;
}

int dequeueFront(DEQueue * q){
    if (isEmpty(q)){
        return -1;
    }
    q->front++;
    return q->data_arr[q->front];
}

int dequeueRear(DEQueue * q){
    if (isEmpty(q)){
        return -1;
    }
    q->rear--;
    return q->data_arr[q->rear];
}

void printQueue(DEQueue * q){
    for (int i = q->front; i < q->rear; i++){
        printf("%d\n", q->data_arr[i+1]);
    }
}

int main(){
    DEQueue * dq1 = initDeQueue(10);
    enqueueRear(dq1, 12);
    enqueueRear(dq1, 34);
    enqueueRear(dq1, 67);
    // dequeueRear(dq1);
    enqueueRear(dq1, 77);
    enqueueRear(dq1, 89);
    dequeueFront(dq1);
    enqueueFront(dq1, 13);

    printQueue(dq1);
    return 0;
}