#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next_node;
} Node;

Node * initCircularLL(){
    Node * empty_node = (Node*) malloc(sizeof(Node));
    empty_node->data = -1;
    empty_node->next_node = empty_node;
    return empty_node;
}

void append(Node * empty_node, int data){
    // Time complexity in worse case O(n)
    // Time complexity in best case O(1)
    Node * head_node = empty_node->next_node;
    Node * last_node = head_node;
    do {
        last_node = last_node->next_node;
    } while (head_node != last_node->next_node);
    Node * new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    last_node->next_node = new_node;
    if (empty_node != head_node) {
        new_node->next_node = head_node;
    }
    else{
        new_node->next_node = new_node;
    }
}

void printCircularLL(Node * empty_node){
    // Time complexity in worse case O(n)
    Node * head_node = empty_node->next_node;
    do {
        printf("%d, ", head_node->data);
        head_node = head_node->next_node;
    } while (empty_node->next_node != head_node);
    printf("\b\b \n");
}

void delete(Node * empty_node, int index){
    // Time complexity in worse case O(n)
    // Time complexity in best case O(1)
    Node * prev_node = empty_node;
    Node * to_delete = empty_node->next_node;
    for (int i = 0; i < index; i++){
        to_delete = to_delete->next_node;
        prev_node = prev_node->next_node;
    }
    if (to_delete->next_node == empty_node->next_node){
        prev_node->next_node = empty_node->next_node;
        free(to_delete);
        return;
    }
    Node * to_free = to_delete->next_node;
    to_delete->data = to_delete->next_node->data;
    to_delete->next_node = to_delete->next_node->next_node;
    free(to_free);
}

void insert(Node * empty_node, int index, int data){
    // Time complexity best case O(1)
    // Time complexity worse case O(n)
    Node * prev_node = empty_node;
    Node * insert_at = empty_node->next_node;
    for (int i = 0; i < index; i++){
        prev_node = prev_node->next_node;
        insert_at = insert_at->next_node;
    }
    if (insert_at == empty_node->next_node && index != 0){
        Node * new_node = (Node*) malloc(sizeof(Node));
        new_node->data = data;
        new_node->next_node = empty_node->next_node;
        prev_node->next_node = new_node;
        return;
    }
    Node * new_node = (Node*) malloc(sizeof(Node));
    new_node->data = insert_at->data;
    new_node->next_node = insert_at->next_node;
    insert_at->data = data;
    insert_at->next_node = new_node;
}

int main(){
    Node * cl1 = initCircularLL();
    append(cl1, 90);
    append(cl1, 78);
    append(cl1, 21);
    append(cl1, 56);
    append(cl1, 78);
    append(cl1, 22);
    printCircularLL(cl1);
    printf("AFTER INSERTION\n");
    insert(cl1, 10, 100);
    insert(cl1, 6, 12);
    printCircularLL(cl1);
    printf("AFTER DELETION\n");
    delete(cl1, 1);
    printCircularLL(cl1);
    return 0;
}