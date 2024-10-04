#include<stdio.h>
#include<math.h>

int main(void)
{
    int a = 3;
    printf("%d", isnormal(a));
    //printf("%d\n", 0/0);
    printf("%d\n", a>>1);
    printf("%d\n", a<<1);
    printf("%d\n", a<<3);
    printf("%d\n", a>>4);

}