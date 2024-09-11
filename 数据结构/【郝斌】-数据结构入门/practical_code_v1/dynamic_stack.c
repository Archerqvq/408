// date: 22-01-2024 - by lin

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *pNext;
} NODE, *PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;
} STACK, *PSTACK;

void init(PSTACK pS);
void push(PSTACK pS, int val);
bool pop(PSTACK pS, int *pVal);
void traverse(PSTACK pS);
bool empty(PSTACK pS);
bool clear(PSTACK pS);

int main(void)
{
    STACK s;
    PSTACK pS = &s;
    int ret_val;

    init(pS);
    push(pS, 1);
    push(pS, 2);
    push(pS, 3);
    push(pS, 4);
    push(pS, 5);
    push(pS, 6);
    traverse(pS);
    if (true == pop(pS, &ret_val))
    {
        printf("pop succeeded and the value is %d \n", ret_val);
    }
    else
    {
        printf("pop failed\n");
    }
    clear(pS);

    if (true == pop(pS, &ret_val))
    {
        printf("pop succeeded and the value is %d \n", ret_val);
    }
    else
    {
        printf("pop failed\n");
    }

    return 0;
}

void init(PSTACK pS)
{
    // Create a Node that dont store data
    pS->pTop = (PNODE)malloc(sizeof(NODE));

    if (NULL == pS->pTop)
    {
        printf("Dynamic memory allocation failed\n");
        exit(-1);
    }
    else
    {
        pS->pBottom = pS->pTop;
        pS->pBottom->pNext = NULL;
    }
}

void push(PSTACK pS, int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));

    if (NULL == pNew)
    {
        printf("Dynamic memory allocation failed\n");
        exit(-1);
    }

    pNew->data = val;
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
}

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

bool empty(PSTACK pS)
{
    if (pS->pTop == pS->pBottom)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool pop(PSTACK pS, int *pVal)
{
    bool res = false;

    if (true == empty(pS))
    {
        // Do nothing
    }
    else
    {
        // Save the popped node first
        PNODE p = pS->pTop;
        *pVal = pS->pTop->data;
        pS->pTop = pS->pTop->pNext;
        free(p);
        p = NULL;
        res = true;
    }

    return res;
}

bool clear(PSTACK pS)
{
    bool res = false;
    PNODE p;

    if (true == empty(pS))
    {
        // Do nothing
    }
    else
    {
        while (pS->pTop != pS->pBottom)
        {
            p = pS->pTop;
            pS->pTop = pS->pTop->pNext;
            free(p);
        }

        pS->pTop = pS->pBottom;

        res = true;
    }

    return res;
}