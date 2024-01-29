// data: 22-1-2024 - by lin
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *pBase;
    int cnt;
    int len;
} arr, *parr;

// void init_arr(parr array, int length);
void init_arr(parr *array, int length);
bool arr_append(parr array, int val);
bool is_full(parr array);
bool is_empty(parr array);
void show_arr(parr array);
bool insert_arr(parr array, int pos, int val);
bool delete_arr(parr array, int pos, int *ret_val);
void invert_arr(parr array);
bool get_arr(parr array, int val, int *idx);
bool sort_list(parr array);

int main(void)
{
    parr pa;
    int del_val, idx;
	
    init_arr(&pa, 10);
    arr_append(pa, 1);
    arr_append(pa, 2);
    arr_append(pa, 3);
    insert_arr(pa, 4, 4);
    show_arr(pa);

    if (delete_arr(pa, 2, &del_val))
    {
        printf("Deleted element is %d\n", del_val);
    }

	show_arr(pa);
    insert_arr(pa, 3, 5);
	show_arr(pa);
    insert_arr(pa, 2, 11);
	show_arr(pa);
    arr_append(pa, 6);
	show_arr(pa);
    insert_arr(pa, 3, 10);
    show_arr(pa);
    invert_arr(pa);
    show_arr(pa);

    if (get_arr(pa, 1, &idx))
    {
        printf("The index of checked element is %d, and the element is %d\n", idx, *(pa->pBase + idx));
    }

    sort_list(pa);
    show_arr(pa);

    return 0;
}

// void init_arr(parr array, int length)
// {
//     array->pBase = (int *)malloc(sizeof(int) * length);
//     array->cnt = 0;
//     array->len = length;
// }

void init_arr(parr *array, int length)
{
    *array = (parr)malloc(sizeof(arr));
    (*array)->pBase = (int *)malloc(sizeof(int) * length);
    (*array)->cnt = 0;
    (*array)->len = length;
}

bool is_full(parr array)
{
    bool res = false;

    if (array->cnt == array->len)
    {
        res = true;
    }

    return res;
}

bool is_empty(parr array)
{
    bool res = false;

    if (0 == array->cnt)
    {
        res = true;
    }

    return res;
}

bool arr_append(parr array, int val)
{
    bool res = false;

    if (true == is_full(array))
    {
        printf("Array is full\n");
    }

    // array->pBase[array->cnt] = val;
    *((array->pBase) + (array->cnt)) = val;
    array->cnt++;
    res = true;

    return res;
}

void show_arr(parr array)
{
    int i;

    for (int i = 0; i < array->cnt; i++)
    {
        // printf("%d", array->pBase[i]);
        printf("%d  ", *((array->pBase) + i));
    }
    printf("\n");
}

bool insert_arr(parr array, int pos, int val)
{
    bool res = false;
    int i;

    if (true == is_full(array))
    {
        printf("Array is full\r\n");
        return res;
    }

    if (pos < 1 || pos > array->cnt + 1)
    {
        printf("Invalid position to insert\r\n");
        return res;
    }

    for (i = array->cnt - 1; i >= pos - 1; i--)
    {
        // array->pBase[i + 1] = array->pBase[i];
        *(array->pBase + i + 1) = *(array->pBase + i);
    }

    // array->pBase[pos - 1] = val;
    *(array->pBase + (pos - 1)) = val;
    array->cnt++;
    res = true;

    return res;
}

bool delete_arr(parr array, int pos, int *ret_val)
{
    bool res = false;
    int i;

    if (true == is_empty(array))
    {
        printf("Array is empty\r\n");
        return res;
    }

    if (pos < 1 || pos > array->cnt)
    {
        printf("Invalid position to delete\r\n");
        return res;
    }

    // *ret_val = array->pBase[pos - 1];
    *ret_val = *(array->pBase + (pos - 1));

    for (i = pos - 1; i < array->cnt; i++)
    {
        // array->pBase[i] = array->pBase[i + 1];
        *(array->pBase + i) = *(array->pBase + (i + 1));
    }

    array->cnt--;
    res = true;

    return res;
}

void invert_arr(parr array)
{
    int i, tmp;

    for (i = 0; i < array->cnt / 2; i++)
    {
        // tmp = array->pBase[i];
        // array->pBase[i] = array->pBase[array->cnt - i - 1];
        // array->pBase[array->cnt - i - 1] = tmp;
        tmp = *(array->pBase + i);
        *(array->pBase + i) = *(array->pBase + array->cnt - 1 - i);
        *(array->pBase + array->cnt - 1 - i) = tmp;
    }
}

bool get_arr(parr array, int val, int *idx)
{
    bool res = false;
    int i;

    if (true == is_empty(array))
    {
        printf("Array is empty\r\n");
        return res;
    }

    for (i = 0; i < array->cnt; i++)
    {
        // if (array->pBase[i] == val)
        if (*(array->pBase + i) == val)
        {
            *idx = i;
            res = true;
            break;
        }
    }

    return res;
}

// bubble sort - descending order
bool sort_list(parr array)
{
    bool res = false;
    int i, j, tmp;
    int *p = array->pBase;

    if (true == is_empty(array))
    {
        printf("Array is empty\r\n");
        return res;
    }

    for (i = 0; i < array->cnt; i++)
    {
        for (j = 0; j < array->cnt - 1 - i; j++)
        {
            // if (p[j] < p[j + 1])
            // {
            //     tmp = p[j];
            //     p[j] = p[j + 1];
            //     p[j + 1] = tmp;
            // }

            if (*(p + j) < *(p + j + 1))
            {
                tmp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = tmp;
            }
        }
        p = array->pBase;
    }

    res = true;
    return res;
}