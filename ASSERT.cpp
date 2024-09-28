#include"ASSERT.h"

switch_if_ok stack_assert(my_stack* stk)
{
    if (stk->data == NULL)
        stk->status += DATA_NULL;

    if (stk->capacity == NAN)
        stk->status += CAPACITY_NAN;

    if (stk->size == NAN or stk->size < 0)
        stk->status += SIZE_NAN;
        
    if (stk->status != ALL_OK)
        return FAILURE;
    else
        return SUCCESS;
}

void my_stack_dump(my_stack* stk, const char* name, const char* file, int line)
{
    static int n_calls = 0;
    int index = 1;

    printf(RED("ERROR in line %d, in file %s, in function %s\n"), line, file, name);
    
    printf("----------Found issues so far in \"stk\"----------\n");
     
    if (stk->status >= MY_UNDERFLOW)
        printf(YELLOW("%d) Underflow, please try again. There're no elements in the stack satisfying your need\n"), index++);

    if ((int)(stk->status%10000) >= GET_MEMORY_FAIL)
        printf(YELLOW("%d) Get memory couldn't find a spot\n"), index++);

    if ((int)(stk->status%1000) == SIZE_NAN)
        printf(YELLOW("%d) Size of stack is NAN or less then 0\n"), index++);

    if ((int)(stk->status%100) == CAPACITY_NAN)
        printf(YELLOW("%d) Capacity of stack is invalid\n"), index++);

    if ((int)(stk->status%10) >= DATA_NULL)
        printf(YELLOW("%d) Data turned out to be NULL\n"), index++);
    
    if (stk->status == ALL_OK)
        printf(GREEN("* Nothing found\n"));

    printf("-------------------------\n");
    printf(MAGENTA("It's your %d call\n"), ++n_calls);
    printf("-------------------------\n");
    printf("Adress in which \"stk\"  is saved is" CYAN(" 0x %p\n"), stk);
    printf("Adress in which \"data\" is saved is" CYAN(" 0x %p\n"), stk->data);
    printf(BLUE("capasity = %2d\nsize     = %2d\n"), stk->capacity, stk->size);
    
    if (stk->data != NULL)
    {
        if (stk->size == 0)
            printf(CYAN("Nothing to print. Stack is empty.\n"));
        else
        {
            for (int i = 0; i < stk->size; i++)
            {
                printf("[x_%d] == %lg\n", i, stk->data[i]);
            }
        }
    }
}