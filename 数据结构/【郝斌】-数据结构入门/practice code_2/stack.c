/**
 * @file stack.c
 * @author Achar
 * @version 1.0
 * @brief Review
 *
 * @date 2023-10-27
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int data;           // data area
    struct Node *pNext; // pointer area
} NODE, *PNODE;

typedef struct Stack
{
    PNODE pTop;    // Pointer to the top node of the stack
    PNODE pBottom; // Pointer to the bottom node of the stack
} STACK, *PSTACK;

void init_stack(PSTACK pS);
void push(PSTACK pS, int val);
bool pop(PSTACK, int *);
void traverse(PSTACK pS);
bool empty(PSTACK);
void clear(PSTACK); // Clear up the stack

int main(void)
{
    STACK S;
    PSTACK pS = &S;
    int val;

    init_stack(pS);
    push(pS, 1);
    push(pS, 2);
    push(pS, 3);
    push(pS, 4);
    push(pS, 5);
    push(pS, 6);
    traverse(pS);
    if (pop(pS, &val))
    {
        printf("pop succeeded and the value is %d \n", val);
    }
    else
    {
        printf("pop failed! \n");
    }
    clear(pS);

    if (pop(pS, &val))
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
void init_stack(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));

    if (pS->pTop == NULL)
    {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    else
    {
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;
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
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
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
    {
        return true;
    }
    else
    {
        return false;
    }
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
    if (empty(pS))
    {
        return false;
    }
    else
    {
        PNODE r = pS->pTop;
        *pVal = pS->pTop->data;
        pS->pTop = pS->pTop->pNext;
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
    if (empty(pS))
    {
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