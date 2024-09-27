#include"stack_functions.h"

int my_stack_ctor(my_stack* stk, int size)
{
    stk->data = (stack_elem_t*)calloc(size, sizeof(stack_elem_t));
    assert(stk->data != NULL);
    stk->capacity = size*sizeof(stack_elem_t);
    stk->size = 0;
    return 1;
}

int my_stack_push(my_stack* stk, stack_elem_t value)
{
    assert(stk != NULL);
    assert(value != NAN);
    
    stk->data[stk->size++] = value;
}

stack_elem_t my_stack_pop(my_stack* stk)
{
    assert(stk->size > 0);
    return stk->data[--(stk->size)];
}

int my_stack_dtor(my_stack* stk)
{
    assert(stk != NULL);
    free(stk); stk = NULL;
}

void my_stack_dump(my_stack* stk)
{
    assert(stk != NULL);
    static int n_calls = 0;

    printf("-------------------------\n");
    printf("It's your %d call\n", ++n_calls);
    printf("-------------------------\n");
    printf("Adress in which \"stk\"  is saved is %p\n", stk);
    printf("Adress in which \"data\" is saved is %p\n", stk->data);
    printf("capasity = %2d\nsize     = %2d\n", stk->capacity, stk->size);
}

RESULT_OF_OPERATION ckeck_if_ok(my_stack* stk)
{
    if (stk->data == NULL)
        return FAILURE;
    else
        return SUCCESS;
}

void stack_assert(my_stack* stk)
{
    
}