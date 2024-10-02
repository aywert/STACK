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
    int left_block;
    stack_elem_t* data;
    const char* name;
    const char* file;
    const char* function;
    int line;

    int capacity;
    int size;
    int status;
    int add_info;

    int right_block;
};

enum switch_if_ok
{
    MY_UNDERFLOW    = 32,
    GET_MEMORY_FAIL = 16,
    SIZE_NAN        =  8,
    CAPACITY_NAN    =  4, // 1 << 3
    DATA_NULL       =  2, // 1 << 2
    ALL_OK          =  0, // 1 << 1
    SUCCESS         =  1, // 1 << 0
    FAILURE         = -1,
};

switch_if_ok my_stack_ctor(my_stack* stk, int size, const char* name, int line, const char* file, const char* function);
switch_if_ok my_stack_dtor(my_stack* stk, int line, const char* file, const char* function);    
switch_if_ok my_stack_push(my_stack* stk, stack_elem_t value, const char* function, const char* file, int line);
switch_if_ok my_stack_pop(my_stack* stk, stack_elem_t* x, const char* function, const char* file, int line);
void my_stack_dump(my_stack* stk, const char* function, const char* file, int line);
void user_dump(my_stack* stk);

#endif