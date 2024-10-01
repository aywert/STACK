#include"stack_functions.h"
#include"ASSERT.h"

static switch_if_ok get_memory(my_stack* stk, double e);

switch_if_ok my_stack_ctor(my_stack* stk, int size)
{
    assert(size != NAN);
    stk->data = (stack_elem_t*)calloc(size, sizeof(stack_elem_t));
    
    if (stack_assert(stk) == SUCCESS)
    {
        stk->capacity = size;
        stk->size = 0;
        return SUCCESS;
    }
    else
    {
        stk->status += DATA_NULL;
        return FAILURE;
    }
}

switch_if_ok my_stack_push(my_stack* stk, stack_elem_t value)
{
    if (stack_assert(stk) == SUCCESS)
        {
            if (stk->size == stk->capacity)
            {
                if (get_memory(stk, 2) == SUCCESS)
                {
                    stk->data[stk->size++] = value;
                    return SUCCESS;
                }
                else
                {
                    stk->status += GET_MEMORY_FAIL;
                    return FAILURE;
                }
            }
            else
            { 
                stk->data[stk->size++] = value;
                return SUCCESS;
            }
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
                stk->status += MY_UNDERFLOW;
                return FAILURE;
            }
        else
        {
            if (stk->size <= stk->capacity/4 && stk->capacity >10)
            {
                if (get_memory(stk, 0.5) == SUCCESS)
                {
                    *x = stk->data[--(stk->size)];
                    return SUCCESS;
                }
                else
                {
                    stk->status += GET_MEMORY_FAIL;
                    return FAILURE;
                }
            }
            else
            { 
                *x = stk->data[--(stk->size)];
                return SUCCESS;
            }
            
        }
    }
    else
        return FAILURE;
    
}

switch_if_ok my_stack_dtor(my_stack* stk)
{
    if (stack_assert(stk) == SUCCESS)
    {
        stk->capacity = 0;
        stk->size     = 0;
        free(stk->data); stk->data = NULL;
        
        return SUCCESS;
    }
    else
        return FAILURE;
}

switch_if_ok get_memory(my_stack* stk, double e)
{
    stk->capacity = (int)(stk->capacity * e);
    stack_elem_t* tempor_address = stk->data;
    stk->data = (stack_elem_t*)realloc(tempor_address, (stk->capacity) * sizeof(stack_elem_t));
  
    /*for (int i = 0;  stk->capacity - 1 < i < stk->capacity - 1; i++)
        stk->data[i] = 0;*/

    return stack_assert(stk);
}