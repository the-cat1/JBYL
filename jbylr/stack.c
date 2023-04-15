/* JBYL
 * 
 * jbylr/stack.c
 * 实现FILO栈。
 */

#include <stdlib.h>

#include "jbylr.h"


int init_stack(Stack *stack, int len)
{
    stack->data = (int*)calloc(len, sizeof(int));
    if (stack->data == NULL) return -1;
    stack->len = len;
    stack->flags = SF_DEFALUT;
    stack->sp = 0;

    return 0;
}

int push_stack(Stack *stack, int data)
{
    if (stack->sp == stack->len) {      // 满了
        stack->flags = SF_FULL;
        return -1;
    }
    
    stack->data[stack->sp++] = data;
    return 0;
}

int pop_stack(Stack *stack)
{
    if (stack->sp <= 0) {
        stack->flags = SF_EMPTY;
        return 0;
    }
    
    return stack->data[--stack->sp];
}

int allocad_stack(Stack *stack)
{
    return stack->sp;
}
