#ifndef STACK_FUNCTIONS
#define STACK_FUNCTIONS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>

typedef double stack_elem_t;
const double poison_number = -13;

struct my_stack
{
    stack_elem_t* data;
    int capacity;
    int size;
    int status;
};

enum switch_if_ok
{
    MY_UNDERFLOW       =  100000,
    GET_MEMORY_FAIL =   10000,
    SIZE_NAN        =    1000,
    CAPACITY_NAN    =     100,
    DATA_NULL       =      10,
    ALL_OK          =       0,
    SUCCESS         =       1,
    FAILURE         =      -1,
};

switch_if_ok my_stack_ctor(my_stack* stk, int size);
switch_if_ok my_stack_dtor(my_stack* stk);    
switch_if_ok my_stack_push(my_stack* stk, stack_elem_t value);
switch_if_ok my_stack_pop(my_stack* stk, stack_elem_t* x);
void my_stack_dump(my_stack* stk, const char* name, const char* file, int line);

#endif