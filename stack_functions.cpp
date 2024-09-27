#include"stack_functions.h"
#include"ASSERT.h"

int my_stack_ctor(my_stack* stk, int size)
{
    stk->data = (stack_elem_t*)calloc(size, sizeof(stack_elem_t));
    ASSERT(stk);
    stk->capacity = size*sizeof(stack_elem_t);
    stk->size = 0;
    return 1;
}

int my_stack_push(my_stack* stk, stack_elem_t value)
{
    ASSERT(stk);
    assert(value != NAN);
    
    stk->data[stk->size++] = value;
}

stack_elem_t my_stack_pop(my_stack* stk)
{
    ASSERT(stk);
    assert(stk->size > 0);
    return stk->data[--(stk->size)];
}

int my_stack_dtor(my_stack* stk)
{
    ASSERT(stk);
    free(stk); stk = NULL;
}