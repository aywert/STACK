#include"stack_functions.h"

#define RED(R)     "\x1b[31m" R "\x1b[0m"
#define GREEN(G)   "\x1b[32m" G "\x1b[0m"
#define YELLOW(Y)  "\x1b[33m" Y "\x1b[0m"
#define BLUE(B)    "\x1b[34m" B "\x1b[0m"
#define MAGENTA(M) "\x1b[35m" M "\x1b[0m"
#define CYAN(C)    "\x1b[36m" C "\x1b[0m"

#define ASSERT(X) if(stack_assert(X, __FILE__, __LINE__) == FAILURE) return 0;