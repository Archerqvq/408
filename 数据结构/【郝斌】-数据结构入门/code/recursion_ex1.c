// data: 2024-1-30
// brief: 用递归/循环求阶乘
#include <stdio.h>

// 假定n的值是1或大于1的值
long f(long n)
{
    if(1 == n)
    {
        return 1;
    }
    else
    {
        return f(n - 1) * n;
    }
}

int main(void)
{
    // ----- 循环实现求阶乘 ----- //
    // int val = 5;
    // int i, mult = 1; 
    
    // for(i = 1; i <= val; i++)
    // {
    //     mult = mult * i;
    // }
    // printf("%d的阶乘是%d", val, mult);
    
    // ----- 递归实现求阶乘 ----- //
    int val = 5;
    printf("%d的阶乘是%d \n", val, f(val));

    return 0;
}