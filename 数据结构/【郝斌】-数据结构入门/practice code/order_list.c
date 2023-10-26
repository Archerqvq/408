#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *pBase;
    int cnt;
    int len;
} arr, *parr;

void init_arr(parr array, int length);
bool arr_append(parr array, int val);
bool is_full(parr array);
bool is_empty(parr array);
void show_arr(parr array);
void sort_arr(parr array);
bool insert_arr(parr array, int pos, int val);
bool delete_arr(parr array, int pos, int *ret_val);
void invert_arr(parr array);
bool get_arr(parr array, int val, int *ret_pos);

int main(void)
{
    arr array;
    int deleted_val, val_pos;

    init_arr(&array, 8);
    arr_append(&array, 5);
    arr_append(&array, 4);
    arr_append(&array, 3);
    arr_append(&array, 2);
    arr_append(&array, 1);
    show_arr(&array);
    sort_arr(&array);
    show_arr(&array);
    insert_arr(&array, 2, 10);
    show_arr(&array);
    insert_arr(&array, 6, 11);
    show_arr(&array);
    insert_arr(&array, 8, 12);
    show_arr(&array);
    insert_arr(&array, 10, 13); // Wrong position to insert
    if (delete_arr(&array, 1, &deleted_val))
    {
        printf("%d has been deleted\r\n", deleted_val);
    }
    show_arr(&array);
    invert_arr(&array);
    show_arr(&array);
    if(get_arr(&array, 5, &val_pos))
    {
        printf("Get value input, and its position is %d\r\n", val_pos);
    }

    return 0;
}

/**
 * @brief
 * @param  array            My Param doc
 * @param  length           My Param doc
 */
void init_arr(parr array, int length)
{
    array->pBase = (int *)malloc(sizeof(int) * length);
    array->cnt = 0;
    array->len = length;
}

/**
 * @brief
 * @return true
 * @return false
 */
bool is_full(parr array)
{
    if (array->cnt == array->len)
        return true;
    else
        return false;
}

/**
 * @brief
 * @return true
 * @return false
 *
 */
bool is_empty(parr array)
{
    if (array->cnt == 0)
        return true;
    else
        return false;
}

/**
 * @brief
 * @param  array            My Param doc
 * @param  val              My Param doc
 * @return true
 * @return false
 */
bool arr_append(parr array, int val)
{
    if (is_full(array))
    {
        printf("Array is full\n");
        exit(-1);
    }

    array->pBase[array->cnt] = val;
    array->cnt++;
}

/**
 * @brief
 * @param  array            My Param doc
 */
void show_arr(parr array)
{
    int i;

    for (i = 0; i < array->cnt; i++)
    {
        printf("%d ", array->pBase[i]);
    }
    printf("\n");
}

/**
 * @brief
 * @param  array            My Param doc
 */
void sort_arr(parr array)
{
    int i, j, tmp;

    // Bubble sort
    for (i = 0; i < array->cnt - 1; i++)
    {
        for (j = 0; j < array->cnt - 1 - i; j++)
        {
            if (array->pBase[j] > array->pBase[j + 1])
            {
                tmp = array->pBase[j];
                array->pBase[j] = array->pBase[j + 1];
                array->pBase[j + 1] = tmp;
            }
        }
    }
}

/**
 * @brief
 * @param  array            My Param doc
 * @param  pos              My Param doc
 * @param  val              My Param doc
 */
bool insert_arr(parr array, int pos, int val)
{
    int i;

    if (pos < 1 || pos > array->cnt + 1)
    {
        printf("Wrong position to insert\r\n");

        return false;
    }

    // Move elementes of the array from backward
    for (i = array->cnt - 1; i >= pos - 1; i--)
    {
        array->pBase[i + 1] = array->pBase[i];
    }

    array->pBase[pos - 1] = val;
    array->cnt++;

    return true;
}

/**
 * @brief
 * @param  array            My Param doc
 * @param  pos              My Param doc
 * @param  ret_val          My Param doc
 * @return true
 * @return false
 */
bool delete_arr(parr array, int pos, int *ret_val)
{
    if (pos < 1 || pos > array->cnt)
    {
        printf("There is no such position like that\r\n");

        return false;
    }
    // Get the deleted element before deleting it
    *ret_val = array->pBase[pos - 1];
    // Rearrange the array
    for (int i = pos - 1; i < array->cnt; i++)
    {
        array->pBase[i] = array->pBase[i + 1];
    }

    array->cnt--;

    return true;
}

/**
 * @brief
 * @param  array            My Param doc
 */
void invert_arr(parr array)
{
    int i, tmp;

    for (i = 0; i < array->cnt / 2; i++)
    {
        tmp = array->pBase[i];
        array->pBase[i] = array->pBase[array->cnt - i - 1];
        array->pBase[array->cnt - i - 1] = tmp;
    }
}

/**
 * @brief Get the arr object
 * @param  array            My Param doc
 * @param  val              My Param doc
 * @param  ret_pos          My Param doc
 * @return true
 * @return false
 */
bool get_arr(parr array, int val, int *ret_pos)
{
    int i;

    for (i = 0; i < array->cnt; i++)
    {
        if(array->pBase[i] == val)
        {
            *ret_pos = i + 1;
            return true;
        }
    }

    return false;
}