#include"stack_functions.h"
#include"ASSERT.h"

#define TEMP if(0)

const int capacity_of_stack = 10;

int main(void)
{
    my_stack stk = {};

    MY_STACK_CTOR(&stk, capacity_of_stack);

    for (int j = 0; j < 21; j++)
    {
        MY_STACK_PUSH(&stk, j);
    }

    for (int k = 0; k < 21; k++)
    {
        stack_elem_t x = 0;
        MY_STACK_POP(&stk, &x);
        
        printf("%lg\n", x);
    }
    stack_elem_t z = 0;
    MY_STACK_POP(&stk, &z);
        
    printf("%lg\n", z);
    printf("%lg\n", z);

    my_stack_dtor(&stk);
}
