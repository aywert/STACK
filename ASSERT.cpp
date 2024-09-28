#include"ASSERT.h"

switch_if_ok stack_assert(my_stack* stk)
{
    if (stk->data == NULL)
        stk->status = DATA_NULL;

    if (stk->capacity == NAN)
        stk->status = CAPACITY_NAN;

    if (stk->size == NAN or stk->size < 0)
        stk->status = SIZE_NAN;
        
    if (stk->data == NULL || stk->capacity == NAN || stk->size == NAN || stk->status != ALL_OK)
        return FAILURE;
    else
        return SUCCESS;
}

void my_stack_dump(my_stack* stk, const char* name, const char* file, int line)
{
    static int n_calls = 0;

    printf(RED("ERROR in line %d, in file %s, in function %s\n"), line, file, name);
    
    printf("----------Found issues in \"stk\"----------\n");
    int index = 1; 
    if (stk->status == DATA_NULL)
        printf("%d) Data turned out to be NULL\n", index++);
    if (stk->status == CAPACITY_NAN)
        printf("%d) Capacity of stack is invali\n", index++);
    if (stk->status == SIZE_NAN)
        printf("%d) Size of stack is NAN or less then 0\n", index++);
    if (stk->status == ALL_OK)
        printf("* Nothing found\n");

    printf("-------------------------\n");
    printf(MAGENTA("It's your %d call\n"), ++n_calls);
    printf("-------------------------\n");
    printf("Adress in which \"stk\"  is saved is" CYAN(" %p\n"), stk);
    printf("Adress in which \"data\" is saved is" CYAN(" %p\n"), stk->data);
    printf(BLUE("capasity = %2d\nsize     = %2d\n"), stk->capacity, stk->size);
    
    if (stk->data != NULL)
    {
        for (int i = 0; i < stk->size; i++)
        {
            printf("[x_%d] == %lg\n", i, stk->data[i]);
        }
    }
}