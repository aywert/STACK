#include"stack_functions.h"
#include"ASSERT.h"


const int capacity_of_stack = 10;

int main(void)
{
    my_stack stk = {};

    // stack_elem_t i = 5;
    // //stk.data[3] = 5;
    // MY_STACK_PUSH(&stk, 10);
    MY_STACK_CTOR(&stk, capacity_of_stack);
    
    for (stack_elem_t j = 0; j < 21; j++)
    {
        MY_STACK_PUSH(&stk, j);
        //user_dump(&stk);
    }

    stk.data[6] = 100;
    //stk.size = -999;
    //stk.data90[2] = 5;
    //stk.data[-5] = 5;
    // stk.data[22] = 5;
    //stk.name = NULL;
    
    for (stack_elem_t k = 0; k < 21; k++)
    {
        stack_elem_t x = 0;
        MY_STACK_POP(&stk, &x); 
        //user_dump(&stk);
        //user_dump(&stk);
        //printf("%lg\n", x);
    }

    stack_elem_t w = 0;
    //MY_STACK_POP(&stk, &w);
    MY_STACK_DTOR(&stk);
}
