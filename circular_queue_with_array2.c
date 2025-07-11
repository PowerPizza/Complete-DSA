#include <stdio.h>
#include <stdlib.h>

typedef struct circular_queue {
    int * data_arr;
    int start;
    int end;
    int size;
} CircularQueue;

int isFull(CircularQueue * q){
    if ((q->end + 1) % q->size == q->start) {
        return 1;
    }
    return 0;
}

int isEmpty(CircularQueue * q){
    if (q->end == q->start){
        return 1;
    }
    return 0;
}

void enqueue(CircularQueue * q, int data_){
    if (isFull(q)){
        printf("Queue is full\n");
        return;
    }
    q->end = (q->end + 1) % q->size;
    q->data_arr[q->end] = data_;
}

int dequeue(CircularQueue * q){
    if (isEmpty(q)){
        printf("Queue is empty");
        return -1;
    }
    q->start = (q->start + 1) % q->size;
    return q->data_arr[q->start];
}

int main(){
    CircularQueue * cq1 = (CircularQueue*) malloc(sizeof(CircularQueue));
    cq1->size = 4;
    cq1->data_arr = (int*) malloc(sizeof(int)*cq1->size);
    cq1->start = cq1->end = 0;

    enqueue(cq1, 100);
    enqueue(cq1, 344);
    enqueue(cq1, 322);
    // enqueue(cq1, 121);
    
    printf("DELETED : %d\n", dequeue(cq1));
    printf("DELETED : %d\n", dequeue(cq1));
    enqueue(cq1, 109);
    printf("DELETED : %d\n", dequeue(cq1));
    printf("DELETED : %d\n", dequeue(cq1));
    return 0;
}
