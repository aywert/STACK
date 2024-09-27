#include"stack_functions.h"
#include"ASSERT.h"

#define TEMP if(0)

const int capacity_of_stack = 10;

int main(void)
{
    my_stack stk = {};

    MY_STACK_CTOR(&stk, capacity_of_stack);
    /*
    my_stack_push(&stk, -2.12);
    TEMP my_stack_dump(&stk);
    my_stack_push(&stk, 13.56);
    TEMP my_stack_dump(&stk);
    my_stack_push(&stk, 100.9);
    TEMP my_stack_dump(&stk);
    my_stack_push(&stk, 3.5);
    TEMP my_stack_dump(&stk);
    */
    for (int j = 0; j < 15; j++)
    {
        printf("helpp\n");
        MY_STACK_PUSH(&stk, j);
    }

    for (int k = 0; k < 15; k++)
    {
        //printf("help me\n");
        stack_elem_t x = 0;
        MY_STACK_POP(&stk, &x);
        
        printf("%lg\n", x);
    }

    /*stack_elem_t x_1 = my_stack_pop(&stk);
    TEMP my_stack_dump(&stk);
    stack_elem_t x_2 = my_stack_pop(&stk);
    TEMP my_stack_dump(&stk);
    stack_elem_t x_3 = my_stack_pop(&stk);
    TEMP my_stack_dump(&stk);
    stack_elem_t x_4 = my_stack_pop(&stk);
    TEMP my_stack_dump(&stk);*/

    //printf("%lg %lg %lg %lg\n", x_1, x_2, x_3, x_4);

    /* 
    for (int i = 0; i < capacity_of_stack; i++)
    {
        printf("x_%d == %lg\n", i, stk.data[i]);
    }
    */
    my_stack_dtor(&stk);
}
