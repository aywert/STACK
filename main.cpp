#include"stack_functions.h"
#include"ASSERT.h"


const int capacity_of_stack = 10;

int main(void)
{
    my_stack stk = {};

    MY_STACK_CTOR(&stk, capacity_of_stack);

    for (stack_elem_t j = 0; j < 21; j++)
    {
        MY_STACK_PUSH(&stk, j);
        //printf("%llu\n", stk.data_hash);
        //user_dump(&stk);
    }

    for (stack_elem_t k = 0; k < 21; k++)
    {
        stack_elem_t x = 0;
        MY_STACK_POP(&stk, &x); 
        printf("%lg\n", x);
    }
    stack_elem_t w = 0;
    MY_STACK_POP(&stk, &w);
    MY_STACK_DTOR(&stk);
}
