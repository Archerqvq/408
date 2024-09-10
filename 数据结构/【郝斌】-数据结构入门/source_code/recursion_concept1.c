#include <stdio.h>

void f(void);
void g(void);
void k(void);

void f(void)
{
    printf("fff\n");
    g();
    printf("111\n");
}

void g(void)
{
    printf("ggg\n");
    k();
    printf("222\n");
}

void k(void)
{
    printf("kkk\n");

}

int main(void)
{
    f();
    return 0;
}