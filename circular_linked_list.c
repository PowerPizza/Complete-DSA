#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next_node;
} Node;

Node * initCircularLinkedList(){
    Node * empty_node = (Node*) malloc(sizeof(Node));
    empty_node->next_node = empty_node;
    return empty_node;
}

void addDataNode(Node * cl, int data){
    if (cl->next_node == cl){
        Node * head_node = (Node*) malloc(sizeof(Node));
        head_node->data = data;
        head_node->next_node = head_node;
        cl->next_node = head_node;
        return;
    }

    Node * head_node = cl->next_node;

    while (head_node->next_node != cl->next_node)
    {
        head_node = head_node->next_node;
    }
    
    Node * new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next_node = cl->next_node;
    head_node->next_node = new_node;
}

void printCircularList(Node * cl){
    Node * head_node = cl->next_node;
    do{
        printf("%d\n", head_node->data);
        head_node = head_node->next_node;
    } while (cl->next_node != head_node);
}

void insertData(Node * cl, int index, int data){
    Node * p = cl->next_node;
    Node * q = p->next_node;
    for (int i = 0; i < index; i++){
        if (cl->next_node == p->next_node){
            Node * new_node = (Node*) malloc(sizeof(Node));
            new_node->data = data;
            new_node->next_node = p->next_node;
            p->next_node = new_node;
            return;
        }
        p = q;
        q = q->next_node;
    }
    Node * new_node = (Node*) malloc(sizeof(Node));
    new_node->data = p->data;
    new_node->next_node = q;
    p->data = data;
    p->next_node = new_node;
}

void deleteData(Node * cl, int idx){
    Node * head_node = cl->next_node;
    for (int i = 0; i < idx; i++){
        if (cl->next_node == head_node->next_node->next_node){
            Node * to_free = head_node->next_node;
            head_node->next_node = cl->next_node;
            free(to_free);
            return;
        }
        head_node = head_node->next_node;
    }
    head_node->data = head_node->next_node->data;
    Node * to_free = head_node->next_node;
    head_node->next_node = head_node->next_node->next_node;
    free(to_free);
}

int main(){
    Node * cl1 = initCircularLinkedList();
    // printf("%d\n", cl1);  // empty node's data.
    addDataNode(cl1, 90);
    addDataNode(cl1, 78);
    addDataNode(cl1, 21);
    addDataNode(cl1, 56);
    addDataNode(cl1, 78);
    addDataNode(cl1, 22);
    printCircularList(cl1);
    printf("AFTER INSERTION\n");
    insertData(cl1, 10, 100);
    insertData(cl1, 6, 12);
    printCircularList(cl1);
    printf("AFTER DELETION\n");
    deleteData(cl1, 1);
    printCircularList(cl1);
    return 0;
}