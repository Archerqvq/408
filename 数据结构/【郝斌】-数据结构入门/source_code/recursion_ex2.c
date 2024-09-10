// data: 2024-1-30
// brief: 循环/递归实现前n项和
#include <stdio.h>

long f(long n)
{
    if(1 == n)
    {
        return 1;
    }
    else
    {
        return f(n - 1) + n;
    }
}

int main(void)
{
    // ----- 前n项和循环实现 ----- //
    // int n = 5, sum = 0;
    
    // for(int i = 1; i <= n; i++)
    // {
    //     sum += i;
    // }
    // printf("前%d项和为%d\n", n, sum);
    
    // ----- 前n项和递归实现 ----- //
    int n = 4;
    printf("前%d项和为%d\n", n, f(n));
    
    return 0;
}