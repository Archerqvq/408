/**
 * @file stack.c
 * @author Achar
 * @version 1.0
 * @brief 栈实现 by 郝斌
 *
 * @date 2023-10-26
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *pNext;
} NODE, *PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;
} STACK, *PSTACK; // PSTACK等级与 struct Stack *

void init(PSTACK pS);
void push(PSTACK pS, int val);
bool empty(PSTACK pS);
bool pop(PSTACK, int *); // 把pS所指向的栈出栈一次，并把出栈元素存入pVal形参所指向的变量中，如果出栈失败，返回false，否则返回true
void traverse(PSTACK pS);
void clear(PSTACK); // 清空栈

int main(void)
{
    STACK S; // STACK等价于struct Stack
    int val;

    init(&S);    // 目的是造出一个空栈
    push(&S, 1); // 进栈
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    push(&S, 5);
    push(&S, 6);
    traverse(&S);
    clear(&S); // 清空栈
    if (pop(&S, &val))
    {
        printf("pop succeeded and the value is %d \n", val);
    }
    else
    {
        printf("pop failed! \n");
    }

    return 0;
}

/**
 * @brief
 * @param  pS               My Param doc
 */
void init(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));

    if (NULL == pS->pTop)
    {
        printf("动态内存分配失败!\n");
        exit(-1);
    }
    else
    {
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL; // 等价于pS->pBottom->pNext = NULL;
    }
}

/**
 * @brief
 * @param  pS               My Param doc
 * @param  val              My Param doc
 */
void push(PSTACK pS, int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));

    pNew->data = val;
    pNew->pNext = pS->pTop; // pS->pTop不能改成pS->Bottom
    pS->pTop = pNew;        // 移动栈顶的指针
}

/**
 * @brief
 * @param  pS               My Param doc
 */
void traverse(PSTACK pS)
{
    PNODE p = pS->pTop;

    while (p != pS->pBottom)
    {
        printf("%d  ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

/**
 * @brief
 * @param  pS               My Param doc
 * @return true
 * @return false
 */
bool empty(PSTACK pS)
{
    if (pS->pTop == pS->pBottom)
        return true;
    else
        return false;
}

/**
 * @brief
 * @param  pS               My Param doc
 * @param  pVal             My Param doc
 * @return true
 * @return false
 */
bool pop(PSTACK pS, int *pVal)
{
    if (empty(pS)) // pS本身存放的就是S的地址
    {
        return false;
    }
    else
    {
        PNODE r = pS->pTop;
        *pVal = r->data;
        pS->pTop = r->pNext;
        free(r);
        r = NULL;
    }

    return true;
}

/**
 * @brief
 * @param  pS               My Param doc
 */
void clear(PSTACK pS)
{
    if (empty(pS)) // pS本身存放的就是S的地址
    {
        printf("空栈，清空失败\n");
    }
    else
    {
        PNODE p = pS->pTop;
        PNODE q = NULL;

        while (p != pS->pBottom)
        {
            q = p->pNext;
            free(p);
            p = q;
        }

        pS->pTop = pS->pBottom;
    }
}