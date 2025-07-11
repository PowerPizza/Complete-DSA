#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node * next_node;
} Node;

typedef struct linkedListStack {
    Node * linked_list;
} LinkedListStack;

LinkedListStack * initStack(){
    LinkedListStack * stack_ = (LinkedListStack*) malloc(sizeof(LinkedListStack));
    stack_->linked_list = NULL;
    return stack_;
}

int isEmpty(LinkedListStack * lls){
    if (lls->linked_list == NULL){
        return 1;
    }
    return 0;
}

void push(LinkedListStack * lls, char data){
    Node * new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next_node = lls->linked_list;
    lls->linked_list = new_node;
}

void printStack(LinkedListStack * lls){
    Node * head_node = lls->linked_list;
    while (head_node != NULL)
    {
        printf("%c, ", head_node->data);
        head_node = head_node->next_node;
    }
    printf("\n");
}

void pop(LinkedListStack * lls){
    if (isEmpty(lls)){
        return;
    }
    Node * to_free = lls->linked_list;
    lls->linked_list = lls->linked_list->next_node;
    free(to_free);
}

void releaseStack(LinkedListStack * lls){
    while (!isEmpty(lls)) {
        pop(lls);
    }
    free(lls);
}

int checkExpressionValidity(char * char_arr){
    LinkedListStack * st1 = initStack();
    for (int i = 0; i < strlen(char_arr); i++){
        switch (char_arr[i]) {
            case '(':
                push(st1, '(');
                break;
            case ')':
                if (isEmpty(st1)) return 0;
                pop(st1);
                break;
            default:
                break;
        }
    }

    int is_valid = isEmpty(st1);
    releaseStack(st1);
    return is_valid;
}

int main(int argc, char const *argv[])
{
    LinkedListStack * st1 = initStack();
    char expr[] = "56+(12.3+10+6)-(9-2)+(12*12)";
    printf("is expr valid : %d\n", checkExpressionValidity(expr));

    char expr2[] = "56+(12.3+10+6)-(9-2)+(12*12)";
    printf("is expr valid : %d\n", checkExpressionValidity(expr2));

    return 0;
}
