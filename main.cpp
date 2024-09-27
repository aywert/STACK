#include"stack_functions.h"
#include"ASSERT.h"

const int capacity_of_stack = 10;

int main(void)
{
    my_stack stk = {};
    my_stack_ctor(&stk, capacity_of_stack);
    ASSERT(&stk);

    my_stack_push(&stk, -2.12);
    ASSERT(&stk);

    my_stack_push(&stk, 13.56);
    ASSERT(&stk);

    my_stack_push(&stk, 100.9);
    ASSERT(&stk);

    my_stack_push(&stk, 3.5);
    ASSERT(&stk);

    stack_elem_t x_1 = my_stack_pop(&stk);

    stack_elem_t x_2 = my_stack_pop(&stk);

    stack_elem_t x_3 = my_stack_pop(&stk);

    stack_elem_t x_4 = my_stack_pop(&stk);

    printf("%lg %lg %lg %lg\n", x_1, x_2, x_3, x_4);
    my_stack_dtor(&stk);
}
