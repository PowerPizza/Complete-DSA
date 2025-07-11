#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char operators[] = "+-*/^";
#define DEVISION_PREC 12
#define ADDITION_PREC 11
#define BITWISE_OR_PREC 6

int getOperatorPrecedence(char operator){
    if (operator == '+' || operator == '-'){
        return ADDITION_PREC;
    }
    if (operator == '*' || operator == '/'){
        return DEVISION_PREC;
    }
    if (operator == '^'){
        return BITWISE_OR_PREC;
    }
    else{
        return -1;
    }
}

typedef struct operator_node{
    char operator;
    int precedence;
    struct operator_node * operator_node;
} O_Node;

int isEmpty(O_Node * lls){
    if (lls->operator_node == NULL){
        return 1;
    }
    return 0;
}

void push(O_Node * lls, char operator_){
    O_Node * new_o_node = (O_Node*) malloc(sizeof(O_Node));
    new_o_node->operator = operator_;
    new_o_node->precedence = getOperatorPrecedence(operator_);
    new_o_node->operator_node = lls->operator_node;
    lls->operator_node = new_o_node;
}

char pop(O_Node * lls){
    if (isEmpty(lls)){
        return 'N';
    }
    O_Node * to_free = lls->operator_node;
    char to_ret = to_free->operator;
    lls->operator_node = lls->operator_node->operator_node;
    free(to_free);
    return to_ret;
}

void printStack(O_Node * lls){
    O_Node * head_o_node = lls->operator_node;
    while (head_o_node != NULL) {
        printf("%c | %d\n", head_o_node->operator, head_o_node->precedence);
        head_o_node = head_o_node->operator_node;
    }
}

int includesChar(char * seq, char target){
    char targ[] = {target, '\0'};
    if (strstr(seq, targ) != NULL){
        return 1;
    }
    else{
        return 0;
    }
}

char * infixToPostfix(char * expr){
    O_Node * stack1 = (O_Node*) malloc(sizeof(O_Node));
    stack1->operator_node = NULL;

    char * postfixExpr = (char*) malloc(sizeof(char)*strlen(expr));
    postfixExpr[0] = '\0';

    for (int i = 0; i < strlen(expr); i++){
        if (includesChar(operators, expr[i])){  // runs when expr[i] present in operators.
            while (!isEmpty(stack1) && getOperatorPrecedence(expr[i]) <= stack1->operator_node->precedence){
                int l = strlen(postfixExpr);
                postfixExpr[l] = pop(stack1);
                postfixExpr[l+1] = '\0';
            }
            push(stack1, expr[i]);
        }
        else{
            if (expr[i] == ' ' || expr[i] == '(' || expr[i] == ')'){
                continue;
            }
            int l = strlen(postfixExpr);
            postfixExpr[l] = expr[i];
            postfixExpr[l+1] = '\0';
        }
    }

    while (!isEmpty(stack1)) {
        int l = strlen(postfixExpr);
        postfixExpr[l] = pop(stack1);
        postfixExpr[l+1] = '\0';
    }
    
    return postfixExpr;
}

int main(int argc, char const *argv[])
{
    char expr[] = "A + B - C * D / E ";
    printf("%s\n", infixToPostfix(expr));
    return 0;
}
