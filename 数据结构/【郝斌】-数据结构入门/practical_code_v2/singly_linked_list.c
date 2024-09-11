/**
 * @file singly_linked_list.c
 * @author Archer
 * @version 1.0
 * @brief 
 * 
 * @date 2024-09-11
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data; // Data area
    struct node *p_next; // Pointer area
}node, *p_node;

typedef bool (*cmp_cback)(float x, float y);

p_node list_create(void);
bool is_list_empty(p_node head);
void list_traverse(p_node head);
int list_length(p_node head);
void list_insert(p_node head, int pos, int val);
int list_delete(p_node head, int pos);

bool nums_cmp_cback(float x, float y);
void list_sort(p_node head, cmp_cback callback);

int main(int argc, char **argv)
{
    p_node l = list_create();
    list_traverse(l);
    int len = list_length(l);

    if(len)
    {
        printf("The list has %d node(s)\n", len);
    }

    list_insert(l, 6, 6);
    list_traverse(l);
    len = list_length(l);
    if(len)
    {
        printf("The list has %d node(s)\n", len);
    }

    int ret_val = list_delete(l, 1);
    printf("The deleted value is %d\n", ret_val);
    list_traverse(l);

    list_sort(l, nums_cmp_cback);
    list_traverse(l);

    return 0;
}

p_node list_create(void)
{
    int i, len, val;

    // Create a head node for the singly linked list
    p_node head = (p_node)malloc(sizeof(node));
    if(NULL == head)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    // Create a tail node for nodes assignment
    p_node tail = head;
    tail->p_next = NULL;

    printf("Enter the amount of node that you want to create\n");
    scanf("%d", &len);

    for(i = 0; i < len; i++)
    {
        printf("Plz enter No.%d node: ", i + 1);
        scanf("%d", &val);

        p_node new = (p_node)malloc(sizeof(node));
        if(NULL == new)
        {
            printf("Memory allocation failed\n");
            return NULL;
        }

        new->data = val;
        new->p_next = NULL;
        tail->p_next = new;
        tail = new;
    }

    return head;
}

bool is_list_empty(p_node head)
{
    bool res = false;

    if(NULL == head->p_next)
    {
        res = true;
        return res;
    }
    else
    {
        return res;
    }
}

void list_traverse(p_node head)
{
    if(is_list_empty(head))
    {
        printf("List is empty, there's no need to traverse\n");
    }
    else
    { 
        p_node p = head->p_next;

        while(NULL != p)
        {
            printf("%d  ", p->data);
            p = p->p_next;
        }
        printf("\n");
    }
}

int list_length(p_node head)
{
    int len = 0;
    p_node p = head->p_next;

    while(NULL != p)
    {
        len++;
        p = p->p_next;
    }

    return len;
}

void list_insert(p_node head, int pos, int val)
{
    int len = list_length(head);

    if(pos < 1 || pos > len + 1)
    {
        printf("Invaild postion to insert a node\n");
    }
    else
    {
        int i = 0;
        p_node p = head;
        p_node new = (p_node)malloc(sizeof(node));

        if(NULL == new)
        {
            printf("Memory allocation failed\n");
        }
        else
        {
            new->data = val;

            while(i < pos - 1)
            {
                p = p->p_next;
                i++;
            }            

            new->p_next = p->p_next;
            p->p_next = new;
        }
    }
}

int list_delete(p_node head, int pos)
{
    int len = list_length(head);

    if(0 == len)
    {
        printf("Is' a empty list, there's no need to delete a node\n");
    }    
    else if(pos < 1 || pos > len)
    {   
        printf("Invalid postion to delete a node\n");
    }   
    else
    {
        int i, ret_val;
        p_node p = head, q = NULL;

        for(i = 0; i < pos - 1; i++)
        {
            p = p->p_next;
        }

        q = p->p_next; // q is the node that is needed to delete
        ret_val = q->data; // Save the data before deleting the node
        p->p_next = q->p_next;

        return ret_val;
    }
}

bool nums_cmp_cback(float x, float y)
{
    bool res = false;

    // To change the comparison operator to > or < to decide
    // whether the list is descending order or ascending order
    if(x < y) 
    {
        res = true;
    }

    return res;
}


// Bubble sort
void list_sort(p_node head, cmp_cback callback)
{
    int len = list_length(head);

    if(len == 0)
    {   
        printf("There's no need to sort a empty list\n");
    }
    else
    {
        int i, j, tmp;
        p_node p = head->p_next; // First node
        p_node q = p->p_next; // Second node

        for(i = 0; i < len - 1; i++)
        {
            for(j = 0; j < len - 1 - i; j++)
            {
                if(callback(p->data, q->data))
                {
                    tmp = p->data;
                    p->data = q->data;
                    q->data = tmp;
                }
                p = p->p_next;
                q = p->p_next;
            }
            p = head->p_next;
            q = p->p_next;
        }
    }
}