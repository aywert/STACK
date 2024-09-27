#include"stack_functions.h"

#define RED(R)     "\x1b[31m" R "\x1b[0m"
#define GREEN(G)   "\x1b[32m" G "\x1b[0m"
#define YELLOW(Y)  "\x1b[33m" Y "\x1b[0m"
#define BLUE(B)    "\x1b[34m" B "\x1b[0m"
#define MAGENTA(M) "\x1b[35m" M "\x1b[0m"
#define CYAN(C)    "\x1b[36m" C "\x1b[0m"

#define ASSERT(X) if(stack_assert(X, __FILE__, __LINE__) == FAILURE) return 0;
#define MY_STACK_CTOR(X, Y) {                                                              \
                            my_stack_ctor(X, Y);                                           \
                            if(stack_assert(X, __FILE__, __LINE__) == FAILURE || Y == NAN) \
                                return 0;                                                  \
                            }

#define MY_STACK_DTOR(X)    {                                                   \
                            if(stack_assert(X, __FILE__, __LINE__) == FAILURE)  \
                                return 0;                                       \
                            else                                                \
                                my_stack_ctor(X);                               \
                            }                              

#define MY_STACK_POP(X, Y) {                                                                               \
                            if(stack_assert(X, __FILE__, __LINE__) == FAILURE || X.size <= 0 || Y == NULL) \
                                return 0;                                                                  \
                            else                                                                           \
                                my_stack_pop(X, Y);                                                        \
                            }                                                        

#define MY_STACK_PUSH(X, Y) {                                                              \
                            if(stack_assert(X, __FILE__, __LINE__) == FAILURE || Y == NAN) \
                                return 0;                                                  \
                            else                                                           \
                                my_stack_push(X, Y);                                       \
                            }
