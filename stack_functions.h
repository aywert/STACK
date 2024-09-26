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

int my_stack_ctor(my_stack* stk, int size);
int my_stack_dtor(my_stack* stk);
int my_stack_push(my_stack* stk, stack_elem_t value);
stack_elem_t my_stack_pop(my_stack* stk);
void my_stack_dump(my_stack* stk);
RESULT_OF_OPERATION ckeck_if_ok(void* ptr);

#endif