// data: 22-01-2024 by lin
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;           // data area
    struct Node *pNext; // pointer area
} NODE, *PNODE;

PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE pHead);
bool insert_list(PNODE pHead, int pos, int val);
bool delete_lsit(PNODE pHead, int pos, int *pVal);
bool sort_list(PNODE pHead);

int main(void)
{
    PNODE pHead = create_list();
    int ret_val, ins_pos, del_pos;

    traverse_list(pHead);
    printf("input the position in the list that you want to insert:\n");
    scanf("%d", &ins_pos);
    if (insert_list(pHead, ins_pos, 10))
    {
        traverse_list(pHead);
    }

    printf("input the position in the list that you want to delete:\n");
    scanf("%d", &del_pos);
    if (delete_lsit(pHead, del_pos, &ret_val))
    {
        printf("%d has been deleted\n", ret_val);
        traverse_list(pHead);
    }

    printf("start to sort list in descending order and print it\n");
    if (sort_list(pHead))
    {
        traverse_list(pHead);
    }
    else
    {
        printf("sorting list occurs errors!\n");
    }

    return 0;
}

PNODE create_list(void)
{
    int i, len, val;

    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if (NULL == pHead)
    {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    PNODE pTail = pHead;
    pTail->pNext = NULL;

    printf("Enter the amount of node that you want to create\n");
    scanf("%d", &len);

    for (i = 0; i < len; i++)
    {
        printf("Plz enter No.%d node: ", i + 1);
        scanf("%d", &val);

        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if (NULL == pNew)
        {
            printf("Memory allocation failed\n");
            exit(-1);
        }
        pNew->data = val;
        pNew->pNext = NULL;
        pTail->pNext = pNew;
        pTail = pNew;
    }

    return pHead;
}

void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    while (NULL != p)
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

bool is_empty(PNODE pHead)
{
    if (NULL == pHead->pNext)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int length_list(PNODE pHead)
{
    int len = 0;
    PNODE p = pHead->pNext;

    while (NULL != p)
    {
        len++;
        p = p->pNext;
    }

    return len;
}

bool insert_list(PNODE pHead, int pos, int val)
{
    bool res = false;
    int i, len;
    len = length_list(pHead);
    PNODE p = pHead;

    if (pos > len + 1 || pos < 1)
    {
        printf("Invalid position\n");
        return res;
    }

    PNODE pNew = (PNODE)malloc(sizeof(NODE));

    if (NULL == pNew)
    {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    pNew->data = val;

    for (i = 0; i < pos - 1; i++)
    {
        p = p->pNext;
    }

    pNew->pNext = p->pNext;
    p->pNext = pNew;
    res = true;

    return res;
}

bool delete_lsit(PNODE pHead, int pos, int *pVal)
{
    bool res = false;
    int i, len;
    len = length_list(pHead);
    PNODE p = pHead;

    if (0 == len || pos > len || pos < 1)
    {
        printf("Invalid position\n");
        return res;
    }

    for (i = 0; i < pos - 1; i++)
    {
        p = p->pNext;
    }

    PNODE q = p->pNext; // Save the node before deleting
    *pVal = q->data;

    p->pNext = p->pNext->pNext;
    free(q);
    res = true;

    return res;
}

// bubble sort - descending order
bool sort_list(PNODE pHead)
{
    bool res = false;
    int i, j, tmp_data;
    int len = length_list(pHead);

    if (len <= 0)
    {
        return res;
    }

    PNODE p = pHead, q;

    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            p = p->pNext;
            q = p->pNext;
            if (p->data < q->data)
            {
                tmp_data = p->data;
                p->data = q->data;
                q->data = tmp_data;
            }
        }
        p = pHead;
    }

    res = true;
    return res;
}

// Another way to implement sort_list
// void sort_list(PNODE pHead)
// {
//     int i, j, t;
//     PNODE p, q;
//     int len = length_list(pHead);

//     for (i = 0, p = pHead->pNext; i < len - 1; i++, p = p->pNext)
//     {

//         for (j = 0, q = p->pNext; j < len - 1 - i; j++, q = q->pNext)
//         {
//             if (p->data > q->data) // Just like a[i] > a[j] in array
//             {
//                 t = p->data;       // Just like t = a[i] in array
//                 p->data = q->data; // Just like a[i] = a[j] in array
//                 q->data = t;       // Just like a[j] = t in array
//             }
//         }

//         // for (j = i + 1, q = p->pNext; j < len; j++, q = q->pNext)
//         // {
//         //     if (p->data > q->data) // Just like a[i] > a[j] in array
//         //     {
//         //         t = p->data;       // Just like t = a[i] in array
//         //         p->data = q->data; // Just like a[i] = a[j] in array
//         //         q->data = t;       // Just like a[j] = t in array
//         //     }
//         // }
//     }
// }
