#include <stdio.h>

void f(int n)
{
    printf("call f(%d)\n", n);
    if(1 == n)
    {
        // Do nothing        
    }
    else
    {
       f(n - 1); 
    }
    printf("leave f(%d)\n", n);
}

int main(void)
{
    f(3);
    return 0;
}