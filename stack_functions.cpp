#include"stack_functions.h"
#include"ASSERT.h"

int my_stack_ctor(my_stack* stk, int size)
{
    stk->data = (stack_elem_t*)calloc(size, sizeof(stack_elem_t));
    stk->capacity = size*sizeof(stack_elem_t);
    stk->size = 0;
    return 0;
}

int my_stack_push(my_stack* stk, stack_elem_t value)
{
    stk->data[stk->size++] = value;

    if (stk->size == stk->capacity)
       get_memory(stk);
    //if void * realloc( void * ptrmem, size_t size );
    return 0;
}

int my_stack_pop(my_stack* stk, stack_elem_t* x)
{
    *x = stk->data[--(stk->size)];
    return 0;
}

int my_stack_dtor(my_stack* stk)
{
    free(stk); stk = NULL;
    return 0;
}

int get_memory(my_stack* stk)
{
    printf("help me");
    stk->capacity = stk->capacity * 2;
    stk->data = (stack_elem_t*)realloc(stk->data, stk->capacity);  
    ASSERT(stk);
    my_stack_dump(stk); 

    for (int i = 0;  stk->capacity - 1 < i < stk->capacity - 1; i++)
        stk->data[i] = (stack_elem_t)0;
    return 0;
}