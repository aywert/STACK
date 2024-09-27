#include"ASSERT.h"

switch_if_ok stack_assert(my_stack* stk)
{
    if (stk->data == NULL || stk->capacity == NAN || stk->size == NAN)
        return FAILURE;
    else
        return SUCCESS;
}

void my_stack_dump(my_stack* stk, const char* name, const char* file, int line)
{
    static int n_calls = 0;
    printf("me name is %s\n", name);
    printf(RED("ERROR in line %d, in file %s\n"), line, file);
    printf("-------------------------\n");
    printf(MAGENTA("It's your %d call\n"), ++n_calls);
    printf("-------------------------\n");
    printf("Adress in which \"stk\"  is saved is %p\n", stk);
    printf("Adress in which \"data\" is saved is %p\n", stk->data);
    printf(BLUE("capasity = %2d\nsize     = %2d\n"), stk->capacity, stk->size);
    
    if (stk->data != NULL)
    {
        for (int i = 0; i < stk->size; i++)
        {
            printf("x_%d == %lg\n", i, stk->data[i]);
        }
    }
}