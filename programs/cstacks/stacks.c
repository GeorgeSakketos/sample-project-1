#include <stdio.h>
#include <stdlib.h>
#include "ADTStack.h"

#define getVar(var) #var

typedef int* PointerInt;

void stack_stats(Stack stack){
    char tempvalue;
    int size = stack_size(stack);

    printf("\nSize of Stack %s: %d\n", getVar(stack), size);
    
    printf("\nYou are about to print AND empty variable %s. (y/n): ", getVar(stack));
    if(scanf("%s", &tempvalue) == 1 && tempvalue == 'y'){
        for(int i = 0; i < size; i++){
            PointerInt stackv = stack_top(stack);
            printf("Position %d: %d\n", i+1, *stackv);
            stack_remove_top(stack);
        }
    }
}

void stack_test_values(Stack stack){
    PointerInt value = malloc(sizeof(int));
    *value = 10;

    PointerInt value2 = malloc(sizeof(int));
    *value2 = 12;

    stack_insert_top(stack, value);

    stack_insert_top(stack, value2);
}

int main(void){
    Stack astack = stack_create(free);

    stack_test_values(astack);

    stack_stats(astack);

    stack_destroy(astack);
}
