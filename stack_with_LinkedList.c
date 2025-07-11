#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next_node;
} Node;

typedef struct LinkedListStack {
    int size;
    int used_size;
    Node * linked_list;
} LinkedListStack;

LinkedListStack * initLinkedListStack(int size){
    // Time complexity O(1)
    LinkedListStack * stack1 = (LinkedListStack*) malloc(sizeof(LinkedListStack));
    stack1->size = size;
    stack1->used_size = 0;
    stack1->linked_list = NULL;
    return stack1;
}

int isFull(LinkedListStack * lls){
    // Time complexity O(1)
    if (lls->used_size == lls->size){
        return 1;
    }
    return 0;
}

int isEmpty(LinkedListStack * lls){
    // Time complexity O(1)
    if (lls->linked_list == NULL){
        return 1;
    }
    return 0;
}

void push(LinkedListStack * lls, int data){
    // Time complexity O(1)
    Node * new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL || isFull(lls)){
        printf("Error : stack over flow\n");
        return;
    }
    new_node->data = data;
    new_node->next_node = lls->linked_list;
    lls->linked_list = new_node;
    lls->used_size++;
}

void printStack(LinkedListStack * lls){
    // Time complexity O(n)
    Node * head_node = lls->linked_list;
    while (head_node != NULL)
    {
        printf("%d, ", head_node->data);
        head_node = head_node->next_node;
    }
    printf("\n");    
}

int pop(LinkedListStack * lls){
    // Time complexity O(1)
    Node * to_free = lls->linked_list;
    if (isEmpty(lls)){
        return -1;
    }
    int to_ret = to_free->data;
    lls->linked_list = lls->linked_list->next_node;
    lls->used_size--;
    free(to_free);
    return to_ret;
} 

int peek(LinkedListStack * lls, int index){
    // Time complexity O(n) best case when index is 0 and worst case when index is same as used size
    if (index+1 > lls->used_size){
        return -1;
    }
    Node * head_node = lls->linked_list; 
    for (int i = 0; i < index; i++){
        head_node = head_node->next_node;
    }
    return head_node->data;
}

int stackTop(LinkedListStack * lls){
    // Time complexity O(1)
    return lls->linked_list->data;
}

int stackBotton(LinkedListStack * lls){
    // Time complexity O(n)
    Node * head_node = lls->linked_list;
    while (head_node->next_node != NULL) {
        head_node = head_node->next_node;
    }
    return head_node->data;
}


int main(){
    LinkedListStack * stack1 = initLinkedListStack(5);
    push(stack1, 10);
    push(stack1, 12);
    push(stack1, 14);
    push(stack1, 45);
    // push(stack1, 55);
    // push(stack1, 67);
    // push(stack1, 64);
    printStack(stack1);
    printf("Is stack full ? : %d\n", isFull(stack1));
    printf("Is stack empty ? : %d\n", isEmpty(stack1));

    // printf("POPPED DATA : %d\n", pop(stack1));
    // printf("POPPED DATA : %d\n", pop(stack1));
    // printf("POPPED DATA : %d\n", pop(stack1));
    // printf("POPPED DATA : %d\n", pop(stack1));
    printStack(stack1);

    printf("Peeking at 2 : %d\n", peek(stack1, 2));
    printf("Peeking at 0 : %d\n", peek(stack1, 0));
    printf("Peeking at 1 : %d\n", peek(stack1, 1));
    printf("Peeking at 3 : %d\n", peek(stack1, 3));

    printf("Stack Top Value : %d\n", stackTop(stack1));
    printf("Stack Bottom Value : %d\n", stackBotton(stack1));

    return 0;
}