#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next_node;
} Node;

Node * initLinkedList(int data){
    Node * new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next_node = NULL;
}

void appendNode(Node * linked_lst, int data){
    // Time complexity O(n)
    Node * head_node = linked_lst;
    while (head_node -> next_node != NULL) {
        head_node = head_node->next_node;
    }
    Node * new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next_node = NULL;
    head_node->next_node = new_node;
    
}

void insertNode(Node * linked_lst, int index, int data){
    // Time complexity O(1) if index is 0
    // Time complexity O(n) if index is any n integer.
    Node * head_node = linked_lst;
    while (index) {
        head_node = head_node->next_node;
        index--;
    }
    if (head_node == NULL){
        appendNode(linked_lst, data);
        return;
    }
    Node * new_node = (Node*) malloc(sizeof(Node));
    new_node->data = head_node->data;
    new_node->next_node = head_node->next_node;
    head_node->data = data;
    head_node->next_node = new_node;
}

void deleteNode(Node * linked_lst, int index){
    // Time complexity O(1) if index is 0
    // Time complexity O(n) if index is any n integer.
    Node * hn2 = linked_lst;
    Node * head_node = linked_lst;
    while (index) {
        hn2 = head_node;
        head_node = head_node->next_node;
        index--;
    }
    if (head_node->next_node == NULL){
        Node * to_free = hn2->next_node;
        hn2->next_node = NULL;
        free(to_free);
        return;
    }
    Node * to_free = head_node->next_node;
    head_node->data = head_node->next_node->data;
    head_node->next_node = head_node->next_node->next_node;
    free(to_free);
}

void printLinkedList(Node * linked_lst){
    // Time complexity O(n)
    Node * head_node = linked_lst;
    printf("%d\n", head_node->data);
    while (head_node->next_node != NULL) {
        head_node = head_node->next_node;
        printf("%d\n", head_node->data);
    }
}

int main(){
    Node * linked_lst1 = initLinkedList(20);
    appendNode(linked_lst1, 12);
    appendNode(linked_lst1, 34);
    appendNode(linked_lst1, 45);
    appendNode(linked_lst1, 56);
    appendNode(linked_lst1, 67);
    appendNode(linked_lst1, 76);
    appendNode(linked_lst1, 89);
    insertNode(linked_lst1, 8, 100);

    printf("BEFORE DELETION\n");
    printLinkedList(linked_lst1);

    // deleteNode(linked_lst1, 1);
    // deleteNode(linked_lst1, 2);
    deleteNode(linked_lst1, 8);
    deleteNode(linked_lst1, 0);

    printf("AFTER DELETION\n");
    printLinkedList(linked_lst1);
}