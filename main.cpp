#include"stack_functions.h"
#include"ASSERT.h"

#define TEMP if(0)

const int capacity_of_stack = 10;

int main(void)
{
    my_stack stk = {};

    MY_STACK_CTOR(&stk, capacity_of_stack);

    for (stack_elem_t j = 0; j < 21; j++)
    {
        MY_STACK_PUSH(&stk, j);
    }

    for (stack_elem_t k = 0; k < 21; k++)
    {
        stack_elem_t x = 0;
        MY_STACK_POP(&stk, &x); 
        printf("%lg\n", x);
    }
    MY_STACK_DTOR(&stk);
}
