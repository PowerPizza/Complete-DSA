typedef struct arrayStack {
    int * stack;
    int top_element;
    int size;
} ArrayStack;

ArrayStack * initArrayStack(int size);
int isEmpty(ArrayStack * as);
int isFull(ArrayStack * as);
void push(ArrayStack * as, int data);
void printStack(ArrayStack * as);
int pop(ArrayStack * as);
int peek_i(ArrayStack * as, int index);
int peek_l(ArrayStack * as, int index);
int stackTop(ArrayStack * as);
int stackBottom(ArrayStack * as);