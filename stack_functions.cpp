#include"stack_functions.h"
#include"ASSERT.h"

static int get_memory(my_stack* stk);

switch_if_ok my_stack_ctor(my_stack* stk, int size)
{
    assert(size != NAN);
    stk->data = (stack_elem_t*)calloc(size, sizeof(stack_elem_t));
    assert(stk->data != NULL);

    stk->capacity = size;
    stk->size = 0;
    
    if (stack_assert(stk) == SUCCESS)
    {
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}

switch_if_ok my_stack_push(my_stack* stk, stack_elem_t value)
{
    if (stack_assert(stk) == SUCCESS)
        {
            if (stk->size == stk->capacity)
            {
                get_memory(stk);
            }
            stk->data[stk->size++] = value;
            return SUCCESS;
        }   
    else
        return FAILURE;
}

switch_if_ok my_stack_pop(my_stack* stk, stack_elem_t* x)
{
    if (stack_assert(stk) == SUCCESS)
    {
        if (stk->size == 0)
            {
                printf(YELLOW("Downflow, please try again. There're no elements in the stack satisfying your need\n"));
                return FAILURE;
            }
        else
        {
            *x = stk->data[--(stk->size)];
            return SUCCESS;
        }
    }
    else
        return FAILURE;
}

switch_if_ok my_stack_dtor(my_stack* stk)
{
    if (stack_assert(stk) == SUCCESS)
    {
        free(stk); stk = NULL;
        return SUCCESS;
    }
    else
        return FAILURE;
}

int get_memory(my_stack* stk)
{
    stk->capacity = stk->capacity * 2;
    stack_elem_t* tempor_address = stk->data;
    stk->data = (stack_elem_t*)realloc(tempor_address, (stk->capacity) * sizeof(stack_elem_t));
  
    ASSERT(stk);
    /*for (int i = 0;  stk->capacity - 1 < i < stk->capacity - 1; i++)
        stk->data[i] = 0;*/
    return 0;
}