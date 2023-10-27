/**
 * @file stack.c
 * @author Achar
 * @version 1.0
 * @brief Dynamic stack implement in C
 *
 * @date 2023-10-27
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
bool pop(PSTACK, int *);
bool empty(PSTACK);
void clear(PSTACK); // Clear up the stack

int main(void)
{
    STACK S;
    PSTACK PS = NULL;
    int val;

    // ! Does not work
    // init_stack(PS);
    // push(PS, 1);
    // push(PS, 2);
    // push(PS, 3);
    // push(PS, 4);
    // push(PS, 5);
    // traverse(PS);

    init_stack(&S);
    clear(&S);
    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    push(&S, 5);
    push(&S, 6);
    traverse(&S);
    clear(&S);
    if (pop(&S, &val))
    {
        printf("pop succeeded and the value is %d \n", val);
    }
    else
    {
        printf("pop failed! \n");
    }
    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    push(&S, 5);
    traverse(&S);

    return 0;
}

/**
 * @brief Initilize the void node that is pointed by top and bottom pointer of stack
 * @param  pS               My Param doc
 */
void init_stack(PSTACK pS)
{
    // To create one node that do not contain data but only for the initialization state of the stack
    pS->pTop = (PNODE)malloc(sizeof(NODE));

    // Make sure the node is created successfully, so do some check mechanisms
    if (pS->pTop == NULL)
    {
        printf("Memory allocation failed \n");
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
    // Acording to the features of stack
    // These two statements below should be executed in order
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
        printf("%d\n", p->data);
        p = p->pNext;
    }
}

/**
 * @brief
 * @param  pS               My Param doc
 * @return true
 * @return false
 */
bool empty(PSTACK pS)
{
    // ((pS->pTop) == (pS->pBottom)) ? true : false;
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
    if (empty(pS))
    {
        return false;
    }
    else
    {
        *pVal = pS->pTop->data;
        pS->pTop = pS->pTop->pNext;
        free(pS->pTop);
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
        printf("Empty stack, no need to clear up\n");
    }
    else
    {
        PNODE q = NULL;

        while (pS->pTop != pS->pBottom)
        {
            q = pS->pTop->pNext;
            free(pS->pTop);
            pS->pTop = q;
        }
    }
}