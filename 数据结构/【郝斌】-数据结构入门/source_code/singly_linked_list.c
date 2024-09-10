/**
 * @file singly_linked_list.c
 * @author Achar
 * @version 1.0
 * @brief Singly linked list compliment by Mr.Hao
 *
 * @date 2023-10-26
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;           // 数据域
    struct Node *pNext; // 指针域
} NODE, *PNODE;         // NODE等价于struct Node， PNODE等价于struct Node *

// 函数声明
PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE, int, int); // 在pHead所指向链表的第pos个节点的前面插入一个新的节点，该节点的值为val，且pos的值从1开始
bool delete_list(PNODE, int, int *);
void sort_list(PNODE);

int main(void)
{
    PNODE pHead = NULL; // 等价于struct Node * pHead = NULL;
    int len, ret_val;

    pHead = create_list(); // create_list()功能：创建一个非循环单链表，并将该链表的头节点地址赋值给pHead
    traverse_list(pHead);

    if (is_empty(pHead))
        printf("链表为空\n");
    else
        printf("链表不为空\n");

    len = length_list(pHead);
    printf("链表的长度是%d \n", len);
    sort_list(pHead);
    traverse_list(pHead);
    insert_list(pHead, 4, 33);
    traverse_list(pHead);

    if (delete_list(pHead, 4, &ret_val))
        printf("删除成功，被删除的值是%d \n", ret_val);
    else
        printf("删除失败\n");
    traverse_list(pHead);

    return 0;
}

/**
 * @brief Create a list object
 * @return PNODE
 */
PNODE create_list(void)
{
    int len; // 用来存放有效节点数
    int i;
    int val; // 用来临时存放用户输入的节点的值

    // 分配一个不存放有效数据的头节点
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if (NULL == pHead)
    {
        printf("分配失败，程序终止!\n");
        exit(-1);
    }
    PNODE pTail = pHead;
    pTail->pNext = NULL;

    printf("请输入您需要生成链表节点的个数：len = ");
    scanf("%d", &len);

    for (i = 0; i < len; i++)
    {
        printf("请输入第%d个节点的值： ", i + 1);
        scanf("%d", &val);

        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if (NULL == pNew)
        {
            printf("分配失败，程序终止!\n");
            exit(-1);
        }
        pNew->data = val;
        pNew->pNext = NULL;
        pTail->pNext = pNew; // 首先将pNew挂在上一个节点上
        pTail = pNew;        // 移动尾指针，使其指向链表的最后一个节点
    }

    return pHead;
}

/**
 * @brief
 * @param  pHead            My Param doc
 */
void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext; // 将首指针赋值给p

    while (NULL != p)
    {
        printf("%d  ", p->data);
        p = p->pNext; // 通过遍历指针域来访问链表上不同的节点
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
 * @return int
 */
int length_list(PNODE pHead)
{
    PNODE p = pHead->pNext; // 将首指针赋值给节点p
    int len = 0;

    while (p != NULL)
    {
        p = p->pNext; // 移动指针...
        len++;
    }

    return len;
}

/**
 * @brief
 * @param  pHead            My Param doc
 */
void sort_list(PNODE pHead)
{
    int i, j, t, len;
    PNODE p, q;
    len = length_list(pHead);

    // for (i = 0; i < len - 1; i++)
    // {
    //     for (j = i + 1; j < len; j++)
    //     {
    //         if(a[i] > b[j])
    //         {
    //             t = a[i];
    //             a[i] = b[j];
    //             b[j] = t;
    //         }
    //     }
    // }

    for (i = 0, p = pHead->pNext; i < len - 1; i++, p = p->pNext)
    {
        for (j = i + 1, q = p->pNext; j < len; j++, q = q->pNext)
        {
            if (p->data > q->data) // 类似于数组中的： a[i] > a[j]
            {
                t = p->data;       // 类似于数组中： t = a[i];
                p->data = q->data; // 类似于数组中的：a[i] = a[j];
                q->data = t;       // 类似于数组中的： a[j] = t;
            }
        }
    }
}

/**
 * @brief
 * @param  pHead            My Param doc
 * @param  pos              My Param doc
 * @param  val              My Param doc
 * @return true
 * @return false
 */
bool insert_list(PNODE pHead, int pos, int val)
{
    int i = 0;
    PNODE p = pHead;

    while (NULL != p && i < pos - 1)
    {
        p = p->pNext;
        i++;
    }

    if (i > pos - 1 || NULL == p)
        return false;

    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (NULL == pNew)
    {
        printf("动态分配内存失败!\n");
        exit(-1);
    }
    pNew->data = val;
    PNODE q = p->pNext;
    p->pNext = pNew;
    pNew->pNext = q;

    return true;
}

/**
 * @brief
 * @param  pHead            My Param doc
 * @param  pos              My Param doc
 * @param  pVal             My Param doc
 * @return true
 * @return false
 */
bool delete_list(PNODE pHead, int pos, int *pVal)
{
    int i = 0;
    PNODE p = pHead;

    while (NULL != p && i < pos - 1)
    {
        p = p->pNext;
        i++;
    }

    if (i > pos - 1 || NULL == p)
        return false;

    PNODE q = p->pNext; // 先保存被删除节点的指针
    *pVal = q->data;

    // 删除p节点后的节点
    p->pNext = p->pNext->pNext;
    free(q);
    q = NULL;

    return true;
}