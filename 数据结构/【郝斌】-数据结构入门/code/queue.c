/**
 * @file queue.c
 * @author Achar
 * @version 1.0
 * @brief Queue 实现 by 郝斌
 *
 * @date 2023-10-26
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Queue
{
    int *pBase;
    int front;
    int rear;
} QUEUE;

void init(QUEUE *);
bool en_queue(QUEUE *, int val); // 入队
void traverse_queue(QUEUE *);
bool full_queue(QUEUE *);

int main(void)
{
    QUEUE Q;

    init(&Q);

    return 0;
}

void init(QUEUE *pQ)
{
    pQ->pBase = (int *)malloc(sizeof(int) * 6);
    pQ->front = 0;
    pQ->rear = 0;
}

bool full_queue(QUEUE *pQ)
{
    if ((pQ->rear + 1) % 6 == pQ->front)
        return true;
    else
        return false;
}