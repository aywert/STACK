#define DEBUG
#include"stack_functions.h"

#define RED(R)     "\x1b[31m" R "\x1b[0m"
#define GREEN(G)   "\x1b[32m" G "\x1b[0m"
#define YELLOW(Y)  "\x1b[33m" Y "\x1b[0m"
#define BLUE(B)    "\x1b[34m" B "\x1b[0m"
#define MAGENTA(M) "\x1b[35m" M "\x1b[0m"
#define CYAN(C)    "\x1b[36m" C "\x1b[0m"

#ifdef DEBUG
    #define ON_DEBUG(X) X
#else
    #define ON_DEBUG(X)
#endif


switch_if_ok stack_assert(my_stack* stk);

#define ASSERT(X) {if(stack_assert(X) == FAILURE) return 0;}
#define MY_STACK_CTOR(X, Y)                                                         \
                                                                                    \
    if( my_stack_ctor(X, Y, #X, __LINE__, __FILE__, __PRETTY_FUNCTION__) != SUCCESS)\
    {                                                                               \
        return 0;                                                                   \
    }                                                                               \

#define MY_STACK_DTOR(X)                                                            \
    if(my_stack_dtor(X, __LINE__, __FILE__, __PRETTY_FUNCTION__) != SUCCESS)        \
    {                                                                               \
        return 0;                                                                   \
    }                                                                               \

#define MY_STACK_POP(X, Y)                                                                      \
    if (my_stack_pop(X, Y, __PRETTY_FUNCTION__, __FILE__, __LINE__) != SUCCESS)                 \
    {                                                                                           \
        return 0;                                                                               \
    }                                                                                           \
                                                   

#define MY_STACK_PUSH(X, Y)                                                                  \
    if(my_stack_push(X, Y, __PRETTY_FUNCTION__, __FILE__, __LINE__) != SUCCESS)\
    {                                                                          \
        return 0;                                                              \
    }                                                                          \
