#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hashMap {
    char * key;
    char * value;
    struct hashMap * next_hash_map;
} HashMap;

HashMap * NewHashMap(){
    // O(1)
    HashMap * hmp1 = (HashMap*) malloc(sizeof(HashMap));
    hmp1->next_hash_map = NULL;
    return hmp1;
}

int keyExists(HashMap * hmp, char * key){
    // O(n)
    HashMap * head_hmp = hmp->next_hash_map;
    while (head_hmp != NULL)
    {
        if (strcmp(head_hmp->key, key) == 0){
            return 1;
        }
        head_hmp = head_hmp->next_hash_map;
    }
    return 0;
}

int valueExists(HashMap * hmp, char * value){
    // O(n)
    HashMap * head_hmp = hmp->next_hash_map;
    while (head_hmp != NULL)
    {
        if (strcmp(head_hmp->value, value) == 0){
            return 1;
        }
        head_hmp = head_hmp->next_hash_map;
    }
    return 0;
}

void addKeyValue(HashMap * hmp, char * key, char * value){
    // O(1)
    if (keyExists(hmp, key)){
        printf("Error : key already exists.\n");
        return;
    }
    HashMap * hmp1 = (HashMap*) malloc(sizeof(HashMap));
    hmp1->key = key;
    hmp1->value = value;
    hmp1->next_hash_map = hmp->next_hash_map;
    hmp->next_hash_map = hmp1;
}

void printHashMap(HashMap * hmp){
    // O(n)
    HashMap * head_hmp = hmp->next_hash_map;
    while (head_hmp != NULL) {
        printf("key=%s : value=%s\n", head_hmp->key, head_hmp->value);
        head_hmp = head_hmp->next_hash_map;
    }
}

char * getValueByKey(HashMap * hmp, char * key){
    // O(n)
    HashMap * head_hmp = hmp->next_hash_map;
    while (head_hmp != NULL)
    {
        if (strcmp(head_hmp->key, key) == 0){
            return head_hmp->value;
        }
        head_hmp = head_hmp->next_hash_map;
    }
    return "-1";
}

typedef struct node {
    char data;
    struct node * next_node;
} Node;

void push(Node * lls, char data){
    // O(1)
    Node * new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next_node = lls->next_node;
    lls->next_node = new_node;
}

int isEmpty(Node * lls){
    // O(1)
    if (lls->next_node == NULL){
        return 1;
    } 
    return 0;
}

int pop(Node * lls){
    // O(1)
    if (isEmpty(lls)){
        return -1;
    }
    Node * to_free = lls->next_node;
    lls->next_node = lls->next_node->next_node;
    free(to_free);
    return 1;
}

void printLLS(Node * lls){
    // O(n)
    Node * head_node = lls->next_node;
    while (head_node != NULL)
    {
        printf("%c\n", head_node->data);
        head_node = head_node->next_node;
    }
}

char stackTopValue(Node * lls){
    // O(1)
    return lls->next_node->data;
}

int checMultikParenthesisBalance(char * expr){
    HashMap * bracket_mapper = NewHashMap();
    addKeyValue(bracket_mapper, "(", ")");
    addKeyValue(bracket_mapper, "[", "]");
    addKeyValue(bracket_mapper, "{", "}");

    Node * stack1 = (Node*) malloc(sizeof(Node));
    stack1->next_node = NULL;
    
    for (int i = 0; i < strlen(expr); i++){
        char expr_at[2] = {expr[i], '\0'};
        if (keyExists(bracket_mapper, expr_at)){
            push(stack1, expr[i]);
        }
        else{
            if (!valueExists(bracket_mapper, expr_at)){
                continue;
            }
            if (isEmpty(stack1)){
                return 0;
            }
            char top_val[2] = {stackTopValue(stack1), '\0'};
            if (strcmp(getValueByKey(bracket_mapper, top_val), expr_at) == 0){
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
}
int main(int argc, char const *argv[])
{
    // char expr[] = "{[({(12 + 3) * (4 - [5 / (2 + 1)]) + (9 * (8 - 6))}) + (15 / (3 + 2))]} - [(18 + {7 * [2 - (1 + 3)]}) / (4 + 5)] + {(([1 + 2] * {3 + (4 - 5)})) - [((6 + 7) / 8) * 9]} + (10 * [11 - {12 / (13 + [14 - 15])}]) + ({[((16 + 17) * 18) - {19 + 20}] / (21 + 22)} + [23 - (24 + {25})])";
    char expr[] = "(2+9)*[5+5]/{2 * (23*99)}";
    printf("%d\n", checMultikParenthesisBalance(expr));
    return 0;
}
