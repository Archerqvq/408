/**
 * @file sequential_list.c
 * @author Archer
 * @version 1.0
 * @brief 
 * 
 * @date 2024-09-10
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SEQ_LIST_SIZE (5)
#define ERROR (0xFFFF)

typedef struct sequential_list
{
    int *p_base;
    int cnt;
    int len;
}list, *p_list;

typedef bool (*cmp_cback)(float x, float y);

bool init_list(p_list *l, int len);
bool is_list_full(p_list l);
bool is_list_empty(p_list l);
void list_append(p_list l, int val);
void list_traverse(p_list l);
int list_delete(p_list l, int pos);
void list_insert(p_list l, int pos, int val);
int get_val_from_list(p_list l, int pos);
void list_invert(p_list l);

bool nums_cmp_cback(float x, float y);
void list_sort(p_list l, int len, cmp_cback callback);

int main(int argc, char **argv)
{
    int ret_val;
    p_list l;

    if(init_list(&l, SEQ_LIST_SIZE))
    {
        printf("List initialize successfully\n");
    }

    list_append(l, 1);
    list_append(l, 2);
    list_traverse(l);

    ret_val = list_delete(l, 1);
    printf("The deleted value is %d  \n", ret_val);

    list_traverse(l);
    list_insert(l, 2, 3);
    list_traverse(l);

    int idx = 2;
    ret_val = get_val_from_list(l, idx);
    printf("Get the value %d and it's order in the list is %d\n", ret_val, idx);

    list_append(l, -1);
    list_append(l, 4);
    list_append(l, 5);
    list_traverse(l);

    ret_val = list_delete(l, 1);
    printf("The deleted value is %d  \n", ret_val);    

    list_invert(l);
    list_traverse(l);

    list_sort(l, l->cnt, nums_cmp_cback);
    list_traverse(l);

    return 0;
}

bool init_list(p_list *l, int length)
{
    bool res = false;

    *l = (p_list)malloc(sizeof(list));

    if(NULL == *l)
    {
        printf("List initialization failed\n");
        return res;
    }

    (*l)->len = length;
    (*l)->p_base = (int *)malloc(sizeof(int) * ((*l)->len));
    (*l)->cnt = 0;
    res = true;

    return res;
}

bool is_list_full(p_list l)
{
    bool res = false;

    if(l->cnt == l->len)
    {
        printf("List is full\n");
        res = true;
    }

    return res;
}

bool is_list_empty(p_list l)
{
    bool res = false;

    if(0 == l->cnt)
    {
        printf("List is empty\n");
        res = true;
    }

    return res;    
}

void list_append(p_list l, int val)
{
    int idx = l->cnt;

    if(is_list_full(l))
    {
        printf("List appending failed\n");
    }
    else
    {
        // What if list is not full, then append a new value on it. 
        l->p_base[idx] = val;
        l->cnt++;      
    }
}

void list_traverse(p_list l)
{
    int i;

    if(is_list_empty(l))
    {
        printf("List traversal failed\n");
    }
    else
    {
        printf("Values in the list: ");
        for(i = 0; i < l->cnt; i++)
        {
            printf("%d  ", l->p_base[i]);                
        }
        printf("\n");
    }
}

int list_delete(p_list l, int pos)
{
    int i, ret_val;

    if(is_list_empty(l))
    {
        printf("List deletion failed\n");
        return ERROR;
    }

    if(pos < 0 || pos > l->cnt)
    {
        printf("The value of designated position to be deleted is invalid\n");
        return ERROR;
    }

    ret_val = l->p_base[pos - 1];

    for(i = pos - 1; i < l->cnt; i++)
    {
        l->p_base[i] = l->p_base[i + 1];
    }

    l->cnt--;
    return ret_val;
}

void list_insert(p_list l, int pos, int val)
{
    int i;

    if(is_list_full(l))
    {
        printf("List insertion failed\n");
    }
    else if(pos < 1 || pos > l->cnt + 1)
    {
        printf("It's a invaild place to insert a value\n");
    }
    else
    {
        for(i = l->cnt - 1; i >= pos - 1; i--)
        {
            l->p_base[i + 1] = l->p_base[i];
        }
        l->p_base[pos - 1] = val;
        l->cnt++;
    }
}

int get_val_from_list(p_list l, int pos)
{
    int ret_val;

    if(pos < 0 || pos > l->cnt)
    {
        printf("It's not a valid postion to get a value\n");
        return ERROR;
    }
    else
    {
        ret_val = l->p_base[pos - 1];

        return ret_val;
    }
}

void list_invert(p_list l)
{
    int i;

    if(is_list_empty(l))
    {
        printf("List inverting failed\n");
    }
    else
    {
        int tmp;

        for(i = 0; i < l->cnt / 2; i++)
        {
            tmp = l->p_base[i];
            l->p_base[i] = l->p_base[l->cnt - i - 1];
            l->p_base[l->cnt - i - 1] = tmp;
        }
    }
}

bool nums_cmp_cback(float x, float y)
{
    bool res = false;

    // To change the comparison operator to > or < to decide
    // whether the list is descending order or ascending order
    if(x > y) 
    {
        res = true;
    }

    return res;
}

void list_sort(p_list l, int len, cmp_cback callback)
{
    int i, j;

    if(is_list_empty(l))
    {
        printf("List sorting failed\n");
    }
    else
    {
        int tmp;

        for(i = 0; i < l->cnt - 1; i++)
        {
            for(j = 0; j < l->cnt - i - 1; j++)
            {
                if(callback(l->p_base[j], l->p_base[j + 1]))
                {
                    tmp = l->p_base[j];
                    l->p_base[j] = l->p_base[j + 1];
                    l->p_base[j + 1] = tmp;
                }
            }
        }
    }
}
