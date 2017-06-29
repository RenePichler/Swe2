#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main(void){
    STACK_H *stack;
    stack = create_stack();
    push(stack);
    fflush(stdin);
    push(stack);
    printf("Len: %d\tNEXT: %p\tLAST: %p\n", stack->len, stack->next, stack->last);
    pop(stack);
    printf("Len: %d\tNEXT: %p\tLAST: %p\n", stack->len, stack->next, stack->last);
    return EXIT_SUCCESS;
}
