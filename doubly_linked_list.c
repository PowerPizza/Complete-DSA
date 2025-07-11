#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node * prev_node;
    int data;
    struct node * next_node;
} Node;

Node * initDoublyLinkedList(int data){
    Node * initial_node = (Node*) malloc(sizeof(Node));
    initial_node->data = data;
    initial_node->prev_node = NULL;
    initial_node->next_node = NULL;
    return initial_node;
}

Node * addElementNode(Node * dll, int data){
    /* TIME COMPLEXITY : O(n) */
    Node * head_node = dll;
    while (head_node->next_node != NULL){
        head_node = head_node->next_node;
    }
    Node * new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next_node = NULL;
    new_node->prev_node = head_node;

    head_node->next_node = new_node;
    return new_node;  // returned last node
}

void printDoublyLinkedList(Node * dll, short reversed){
    /*
    When reversed = 0
        Time Complexity : O(n)
    When reversed = 1
        Time Complexity : O(2n) since constant not matters in O(n) so using (Big Theta of 2n)
    */
    if (reversed){
        Node * last_node = dll;
        while (last_node->next_node != NULL) {
            last_node = last_node->next_node;
        }
        printf("%d\n", last_node->data);
        while (last_node->prev_node != NULL) {
            last_node = last_node->prev_node;
            printf("%d\n", last_node->data);
        }
        return;
    }

    Node * head_node = dll;
    printf("%d\n", head_node->data);
    while (head_node->next_node != NULL) {
        head_node = head_node->next_node;
        printf("%d\n", head_node->data);
    }
}

void printDLLByLastNode(Node * last_node){
    /*
    Prints doubly linked list in reverse order in time complexity O(n)
    but it requires last node of doubly linked list.
    */
   printf("%d\n", last_node->data);
    while (last_node->prev_node != NULL) {
        last_node = last_node->prev_node;
        printf("%d\n", last_node->data);
    }
}

void deleteElementNode(Node * dll, int index){
    Node * head_node = dll;
    for (int i = 0; i < index; i++){
        head_node = head_node->next_node;
    }
    Node * to_free = head_node;
    if (head_node->next_node == NULL){
        head_node->prev_node->next_node = NULL;
    }
    else{
        head_node->data = head_node->next_node->data;
        to_free = head_node->next_node;
        head_node->next_node->prev_node = head_node->prev_node;
        head_node->next_node = head_node->next_node->next_node;
    }
    free(to_free);
}

int main(int argc, char const *argv[])
{
    Node * dll1 = initDoublyLinkedList(32);
    addElementNode(dll1, 100);
    addElementNode(dll1, 200);
    addElementNode(dll1, 1400);
    addElementNode(dll1, 33);
    addElementNode(dll1, 24);
    Node * last_node = addElementNode(dll1, 45);

    printf("Doubly Linked List in forward order.\n");
    printDoublyLinkedList(dll1, 0);
    // printf("Doubly Linked List in backward order.\n");
    // printDLLByLastNode(last_node);

    deleteElementNode(dll1, 2);
    deleteElementNode(dll1, 2);
    printf("DOUBLE LINKED LIST AFTER DELETION\n");
    printDoublyLinkedList(dll1, 0);
    return 0;
}
