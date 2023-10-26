/**
 * @file singly_linked_list.c
 * @author Achar
 * @version 1.0
 * @brief
 *
 * @date 2023-10-25
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;           // Data area
    struct Node *pNext; // Pointer area
} NODE, *PNODE;

PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE, int, int);
bool delete_list(PNODE, int, int *);
void sort_list(PNODE);

int main()
{
    PNODE pHead = NULL;
    // Create a singly linked list and return a address to pointer to pHead
    pHead = create_list();
    traverse_list(pHead);

    if (is_empty(pHead))
        printf("List is empty\n");
    else
        printf("List is not empty\n");

    printf("The length of list is %d\n", length_list(pHead));
    sort_list(pHead);
    traverse_list(pHead);

    if (insert_list(pHead, 5, 10))
        printf("Insert success\n");
    else
        printf("Insert failed\n");
    traverse_list(pHead);

    return 0;
}

/**
 * @brief Create a liset object
 * @return PNODE
 */
PNODE create_list(void)
{
    int i;
    int len;
    int val;

    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    // Create a head node to but not to store valid data
    if (NULL == pHead)
    {
        printf("Memory allocation failed\r\n");
        exit(-1);
    }
    PNODE pTail = pHead;
    pTail->pNext = NULL;

    printf("Enter the amount of node that you want to create\r\n");
    scanf("%d", &len);

    for (i = 0; i < len; i++)
    {
        printf("Plz enter No.%d node: ", i + 1);
        scanf("%d", &val);

        PNODE pNew = (PNODE)malloc(sizeof(NODE));

        if (NULL == pNew)
        {
            printf("Memory allocation failed\r\n");
            exit(-1);
        }
        pNew->data = val;
        pNew->pNext = NULL;
        pTail->pNext = pNew;
        pTail = pNew;
    }

    return pHead;
}

/**
 * @brief
 * @param  pHead            My Param doc
 */
void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    while (NULL != p)
    {
        printf("%d  ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

/**
 * @brief
 * @param  pHead            My Param doc
 * @return true
 * @return false
 */
bool is_empty(PNODE pHead)
{
    if (pHead->pNext == NULL)
        return true;
    else
        return false;
}

/**
 * @brief
 * @param  pHead            My Param doc
 * @return true
 * @return false
 */
int length_list(PNODE pHead)
{
    int len = 0;
    PNODE p = pHead->pNext;

    while (p != NULL)
    {
        len++;
        p = p->pNext;
    }

    return len;
}

/**
 * @brief
 * @param  pHead            My Param doc
 */
void sort_list(PNODE pHead)
{
    int i, j, t;
    PNODE p, q;
    int len = length_list(pHead);

    for (i = 0, p = pHead->pNext; i < len - 1; i++, p = p->pNext)
    {

        for (j = 0, q = p->pNext; j < len - 1 - i; j++, q = q->pNext)
        {
            if (p->data > q->data) // Just like a[i] > a[j] in array
            {
                t = p->data;       // Just like t = a[i] in array
                p->data = q->data; // Just like a[i] = a[j] in array
                q->data = t;       // Just like a[j] = t in array
            }
        }

        // for (j = i + 1, q = p->pNext; j < len; j++, q = q->pNext)
        // {
        //     if (p->data > q->data) // Just like a[i] > a[j] in array
        //     {
        //         t = p->data;       // Just like t = a[i] in array
        //         p->data = q->data; // Just like a[i] = a[j] in array
        //         q->data = t;       // Just like a[j] = t in array
        //     }
        // }
    }
}

/**
 * @brief
 * @return true
 * @return false
 */
bool insert_list(PNODE pHead, int pos, int val)
{
    int i, len;
    PNODE q, p, pNew;

    p = pHead; // Assign the head node to p
    pNew = (PNODE)malloc(sizeof(NODE));
    len = length_list(pHead);

    if (pos < 1 || pos > len + 1)
    {
        printf("Invalid position\n");

        return false;
    }

    if (pNew == NULL)
    {
        printf("Memory allocation failed\n");

        return false;
    }
    pNew->data = val;

    // // Approach the pointer that needed be inserted
    // for (i = 0; i < pos - 1; i++)
    // {
    //     // To the node that before pNew
    //     if (i == pos - 1 - 1)
    //     {
    //         q = p;
    //     }
    //     p = p->pNext;
    // }
    // // To the node that after pNew
    // pNew->pNext = p;
    // q->pNext = pNew;

    for (i = 0; i < pos - 1; i++)
    {
        p = p->pNext;
    }

    pNew->pNext = p->pNext;
    p->pNext = pNew;

    return true;
}

/**
 * @brief
 * @param  pHead            My Param doc
 * @param  pos              My Param doc
 * @param  del_val          My Param doc
 * @return true
 * @return false
 */
bool delete_list(PNODE pHead, int pos, int *del_val)
{
    int i;
}