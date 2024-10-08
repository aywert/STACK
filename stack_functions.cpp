#include"stack_functions.h"
#include"ASSERT.h"

static switch_if_ok expand_stack(my_stack* stk);
static switch_if_ok shrink_stack(my_stack* stk);

const int add_info = 2;

switch_if_ok my_stack_ctor(my_stack* stk, int size, const char* name ON_DEBUG(, int line, const char* file, const char* function))
{
    if (stk == NULL || !isnormal(size))
    {
        printf(RED("ERROR Pointer to stack is NULL or size IS NAN\n"));
        return FAILURE;
    }

    stk->data = (stack_elem_t*)calloc(size + add_info, sizeof(stack_elem_t));
    
    if (stk->data == NULL)
    {
        stk->status += DATA_NULL;
        my_stack_dump(stk ON_DEBUG(,function, file, line));
        return FAILURE;
    }

    #ifdef DEBUG
        stk->file     = file;
        stk->line     = line;
        stk->function = function;
    #endif
    
    stk->left_block     = 0xDED;
    stk->right_block    = 0xDED;
    stk->data[0]        = 0xDED; 
    stk->data[size + 1] = 0xDED; 

    for (int i = 1; i <= size; i++)
    {
        stk->data[i] = poison_number;
    }       
    
    stk->data     = &stk->data[1];
    stk->name     = name;
    stk->add_info = add_info;
    stk->capacity = size;
    stk->size     = 0;
    stk->status   = ALL_OK;

    stk->data_hash = get_hash((char*)(&stk->data[0]), stk->size, sizeof(stack_elem_t));
    stk->stk_hash  = get_hash((char*)(&stk->name), 1, sizeof(my_stack)-28);

    return SUCCESS;
}

switch_if_ok my_stack_push(my_stack* stk, stack_elem_t value ON_DEBUG(, const char* function, const char* file, int line))
{
    if (stack_assert(stk) == FAILURE)
    {   
        my_stack_dump(stk ON_DEBUG(, function, file, line));
        return FAILURE;
    }

    if (compare_double(value, poison_number) || (!(isnormal(value)) && (value != 0)))
    {
        printf(RED("ERROR: Given value is poison number or NAN\n"));
        my_stack_dump(stk ON_DEBUG(, function, file, line));
        return FAILURE;
    }

    if(stk->size != stk->capacity)
    { 
        stk->data[stk->size++] = value;
        stk->data_hash = get_hash((char*)&stk->data[0], stk->size, sizeof(stack_elem_t));
        stk->stk_hash  = get_hash((char*)&stk->name, 1, sizeof(my_stack)-28);
        return SUCCESS;
    }

    if (expand_stack(stk) == FAILURE)
    {
        stk->status += GET_MEMORY_FAIL;
        my_stack_dump(stk ON_DEBUG(, function, file, line));
        return FAILURE;
    }

    stk->data[stk->size++] = value;
    stk->data_hash = get_hash((char*)&stk->data[0], stk->size, sizeof(stack_elem_t));
    stk->stk_hash  = get_hash((char*)&stk->name, 1, sizeof(my_stack) - 28);

    return SUCCESS;
}

switch_if_ok my_stack_pop(my_stack* stk, stack_elem_t* x ON_DEBUG(, const char* function, const char* file, int line))
{
    if ((stack_assert(stk) == FAILURE))
    {
        my_stack_dump(stk ON_DEBUG(, function, file, line));
        return FAILURE;
    }

    if (x == NULL)
    {
        printf(RED("given adress is NULL\n"));
        return FAILURE;
    }
    
    if (stk->size == 0)
    {
        stk->status += MY_UNDERFLOW;
        my_stack_dump(stk ON_DEBUG(, function, file, line));
        return FAILURE;
    }

    if (stk->size <= (int)stk->capacity/4 && stk->capacity > 10)
    {
        if (shrink_stack(stk) == FAILURE)
        {
            stk->status += GET_MEMORY_FAIL;
            my_stack_dump(stk ON_DEBUG(, function, file, line));
            return FAILURE;
        }
    
        *x = stk->data[--(stk->size)];
        stk->data[stk->size+1] = poison_number;
        stk->data_hash = get_hash((char*)&stk->data[0], stk->size, sizeof(stack_elem_t));
        stk->stk_hash  = get_hash((char*)&stk->name, 1, sizeof(my_stack)-28);

        return SUCCESS;
    }
  
    *x = stk->data[--(stk->size)];
    stk->data[stk->size+1] = poison_number;
    stk->data_hash = get_hash((char*)&stk->data[0], stk->size, sizeof(stack_elem_t));
    stk->stk_hash  = get_hash((char*)&stk->name, 1, sizeof(my_stack)-28);
    return SUCCESS;

}

switch_if_ok my_stack_dtor(my_stack* stk ON_DEBUG (, int line, const char* file, const char* function))
{
    if (stack_assert(stk) == FAILURE)
    {
        my_stack_dump(stk ON_DEBUG(, function, file, line));
        return FAILURE;
    }

    stk->capacity = 0;
    stk->size     = 0;
    free(stk->data); stk->data = NULL;
    
    printf(GREEN("SUCCESSFULLY CLEARED\n"));
    return SUCCESS;
}

static switch_if_ok expand_stack(my_stack* stk)
{
    
    stk->capacity = stk->capacity * 2;
    stack_elem_t* tempor_address = &stk->data[-1];
    stk->data = (stack_elem_t*)realloc(tempor_address, (stk->capacity + stk->add_info) * sizeof(stack_elem_t));
    
    if (stk->data == NULL)
        return FAILURE;
    
    for (int i = stk->capacity/2; i < stk->capacity; i++)
        stk->data[i+1] = poison_number;

    stk->data[stk->capacity + 1] = 0xDED;
    stk->data = &stk->data[1];    

    return SUCCESS;
}

static switch_if_ok shrink_stack(my_stack* stk)
{
    
    stk->capacity = stk->capacity/2;
    stack_elem_t* tempor_address = &stk->data[-1];
    stk->data = (stack_elem_t*)realloc(tempor_address, (stk->capacity + stk->add_info) * sizeof(stack_elem_t));
    
    if (stk->data == NULL)
        return FAILURE;

    stk->data[stk->capacity + 1] = 0xDED;
    stk->data = &stk->data[1];    

    return SUCCESS;
}

void user_dump(my_stack* stk)
{
    if (stk->data != NULL)
    {
        {
            printf("----------------------\n");
            for (int i = -1; i <= stk->capacity; i++)
            {
                printf("[x_%d] == %lg\n", i, stk->data[i]);
            }
            printf("----------------------\n");
        }
    }
} 