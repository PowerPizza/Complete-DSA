#include <stdio.h>
#include <stdlib.h>
#include "stack_with_array.h"

/*
While searching more on DSA. I found out use of .h files and tried it and hence
all the structures and functions are firstly declared in stack_with_array.h than
implemented here.
*/

ArrayStack * initArrayStack(int size){
    // Initializes an empty stack of given size.
    // Time complexity : O(1)
    ArrayStack * as = (ArrayStack*) malloc(sizeof(ArrayStack));
    as->stack = (int*) malloc(size*sizeof(int));
    as->top_element = -1;
    as->size = size;
    return as;
}

int isEmpty(ArrayStack * as){
    // Checks if stack is empty or not.
    // Time complexity : O(1)
    if (as->top_element < 0){
        return 1;
    }
    return 0;
}

int isFull(ArrayStack * as){
    // Checks if stack is completely full or not.
    // Time complexity : O(1)
    if (as->top_element == as->size-1){
        return 1;
    }
    return 0;
}

void push(ArrayStack * as, int data){
    // Pushes a new element to the stack in LIFO manner.
    // Time complexity : O(1)
    if (isFull(as)){
        printf("Error : Stack over flow : push() failed!\n");
        return;
    }
    as->top_element += 1;
    as->stack[as->top_element] = data;
}

void printStack(ArrayStack * as){
    // Prints whole stack in LIFO manner.
    // Time complexity : O(n)
    for (int i = 0 ; i < as->top_element+1; i++){
        printf("%d\n", peek_i(as, i));
    }
}

int pop(ArrayStack * as){
    // Removes an element from stack in LIFO manner.
    // Time complexity : O(1)
    if (isEmpty(as)){
        printf("Error : Stack is empty : pop() failed!\n");
        return -1;
    }
    int to_ret = as->stack[as->top_element];
    as->top_element -= 1;
    return as->stack[as->top_element+1];
}

int peek_i(ArrayStack * as, int index){
    // To get an element from stack followed by 0 indexed array in LIFO manner.
    // Time complexity : O(1)
    if (index > as->top_element){
        printf("Index out of range\n");
        return -1;
    }
    return as->stack[as->top_element - index];
}

int peek_l(ArrayStack * as, int index){
    // To get an element from stack followed by 1 indexed array in LIFO manner.
    // Time complexity : O(1)
    int calculated_idx = as->top_element - (index - 1);
    if (calculated_idx > as->top_element || calculated_idx < 0){
        printf("Index out of range\n");
        return -1;
    }
    return as->stack[calculated_idx];
}

int stackTop(ArrayStack * as){
    // Gives top most element of stack.
    // Time complexity : O(1)
    return as->stack[as->top_element];
}

int stackBottom(ArrayStack * as){
    // Gives bottom most element of stack.
    // Time complexity : O(1)
    return as->stack[0];
}

int main(){
    ArrayStack * as1 = initArrayStack(10);
    push(as1, 232);
    push(as1, 43);
    push(as1, 23);
    push(as1, 42);
    push(as1, 47);
    printf("BEFORE POP\n");
    printStack(as1);
    printf("popped %d\n", pop(as1));
    // pop(as1);
    printf("AFTER POP\n");
    printStack(as1);
    printf("IS FULL : %d\n", isFull(as1));

    printf("peek : %d\n", peek_i(as1, 0));
    printf("peek : %d\n", peek_i(as1, 1));
    printf("peek : %d\n", peek_i(as1, 2));
    printf("peek : %d\n", peek_i(as1, 3));
    printf("peek : %d\n", peek_i(as1, 4));
    printf("peek : %d\n", peek_i(as1, 5));
    printf("USING PEEK LABEL : \n");
    printf("peek : %d\n", peek_l(as1, 1));
    printf("peek : %d\n", peek_l(as1, 2));
    printf("peek : %d\n", peek_l(as1, 3));
    printf("peek : %d\n", peek_l(as1, 4));
    printf("peek : %d\n", peek_l(as1, 5));
    
    return 0;
}