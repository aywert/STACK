#include"stack_functions.h"

int main(void)
{
    my_stack stk = {};
    my_stack_ctor(&stk, 10);
    my_stack_dump(&stk);

    my_stack_push(&stk, -2.3);
    my_stack_dump(&stk);

    my_stack_push(&stk, 13.56);
    my_stack_dump(&stk);

    my_stack_push(&stk, 3.4);
    my_stack_dump(&stk);

    stack_elem_t x_1 = my_stack_pop(&stk);
    my_stack_dump(&stk);

    stack_elem_t x_2 = my_stack_pop(&stk);
    my_stack_dump(&stk);

    stack_elem_t x_3 = my_stack_pop(&stk);
    my_stack_dump(&stk);
    printf("%lg %lg %lg", x_1, x_2, x_3);
    my_stack_dtor(&stk);
}
