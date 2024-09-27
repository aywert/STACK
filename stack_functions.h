#ifndef STACK_FUNCTIONS
#define STACK_FUNCTIONS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>

typedef double stack_elem_t;

struct my_stack
{
    stack_elem_t* data;
    int capacity;
    int size;
};

enum RESULT_OF_OPERATION
{
    SUCCESS = 0,
    FAILURE = 1,
};

void my_stack_ctor(my_stack* stk, int size);
void my_stack_dtor(my_stack* stk);
void my_stack_push(my_stack* stk, stack_elem_t value);
stack_elem_t my_stack_pop(my_stack* stk);
void my_stack_dump(my_stack* stk);
RESULT_OF_OPERATION check_if_ok(my_stack* stk);
void stack_assert(my_stack* stk, const char* file, int line);

#endif