#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indexOfChar(char * str, char search){
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == search){
            return i;
        }
    }
    return -1;
}

typedef struct node {
    char data;
    struct node * next_node;
} Node;

int isEmpty(Node * lls){
    if (lls->next_node == NULL){
        return 1;
    }
    return 0;
}
char stackTopValue(Node * lls){
    return lls->next_node->data;
}

void push(Node * lls, char data){
    Node * new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next_node = lls->next_node;
    lls->next_node = new_node;
}
void printLLS(Node * lls){
    Node * head_node = lls->next_node;
    while (head_node != NULL) {
        printf("%c, ", head_node->data);
        head_node = head_node->next_node;
    }
    printf("\n");
}
void pop(Node * lls){
    if (isEmpty(lls)){
        return;
    }
    Node * to_free = lls->next_node;
    lls->next_node = lls->next_node->next_node;
    free(to_free);
}


int isParenthesisMatching(char * eqn){
    char * opens = "([{";
    char * closes = ")]}";

    Node * stack1 = (Node*) malloc(sizeof(Node));
    stack1->next_node = NULL;

    for (int i = 0; i < strlen(eqn); i++){
        if (indexOfChar(opens, eqn[i]) >= 0){
            push(stack1, eqn[i]);
        }
        else if (indexOfChar(closes, eqn[i]) >= 0){
            // stack1->next_node->data reperents data of top node of stack.
            if (stack1->next_node != NULL && indexOfChar(opens, stack1->next_node->data) == indexOfChar(closes, eqn[i])){
                pop(stack1);
            }
            else{
                return 0;
            }
        }
    }
    if (isEmpty(stack1)){
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    char eqn[] = "a * b + (c / d] - e)";
    int n = isParenthesisMatching(eqn);
    printf("is valid : %d\n", n);
    return 0;
}
