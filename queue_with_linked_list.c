#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next_node;
} Node;

Node * enqueue(Node * rear, int data){
    Node * new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next_node = NULL;

    rear->next_node = new_node;
    printf("Enqueued : %d\n", data);
    return new_node;
}

Node * dequeue(Node * front){
    if (front->next_node == NULL){
        return front;
    }
    Node * to_ret = front->next_node;
    free(front);
    printf("Dequeued : %d\n", to_ret->data);
    return to_ret;
}

void printQueue(Node * f, Node * r){
    while (f != r){
        f = f->next_node;
        printf("%d\n", f->data);
    }
}

int main(){
    Node * front = (Node*) malloc(sizeof(Node));
    Node * rear = front;

    rear = enqueue(rear, 103);
    rear = enqueue(rear, 104);
    rear = enqueue(rear, 105);
    rear = enqueue(rear, 106);
    rear = enqueue(rear, 1022);

    front = dequeue(front);
    front = dequeue(front);
    front = dequeue(front);
    front = dequeue(front);
    front = dequeue(front);

    rear = enqueue(rear, 106);
    rear = enqueue(rear, 156);
    rear = enqueue(rear, 176);

    printf("FINAL OUTPUT : \n");
    printQueue(front, rear);
    printf("PROGRAM END\n");
    return 0;
}