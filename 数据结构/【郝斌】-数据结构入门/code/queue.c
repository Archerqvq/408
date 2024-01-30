/**
 * @file queue.c
 * @author Achar
 * @version 1.0
 * @brief 循环Queue 实现 by 郝斌
 *
 * @date 2023-1-30
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
bool empty_queue(QUEUE *pQ);
bool out_queue(QUEUE *, int *pVal); // 出队

int main(void)
{
    QUEUE Q;

    init(&Q);
	en_queue(&Q, 1);
	en_queue(&Q, 2);
	en_queue(&Q, 3);
	en_queue(&Q, 4);
	en_queue(&Q, 5);
	en_queue(&Q, 6);
	en_queue(&Q, 7);
	en_queue(&Q, 8);
	traverse_queue(&Q);

    return 0;
}

void init(QUEUE *pQ)
{
	pQ->pBase = (int *)malloc(sizeof(int) * 6); // 创建一块有6个int大小的内存空间
	pQ->front = 0;
	pQ->rear = 0;
}

bool full_queue(QUEUE *pQ)
{
	if(((pQ->rear + 1) % 6) == (pQ->front))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool en_queue(QUEUE *pQ, int val)
{
	if(full_queue(pQ))
	{
		return false;
	}
	else
	{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear + 1) % 6; // rear + 1取余6，使队尾的索引取值范围保持在0~5，从而实现循环队列
		
		return true;
	}	
}

void traverse_queue(QUEUE *pQ)
{
	int i = pQ->front;
	
	while(i != pQ->rear)
	{
		printf("%d ", pQ->pBase[i]);
		i = (i + 1) % 6;
	}
	printf("\n");
}

bool empty_queue(QUEUE *pQ)
{
	if((pQ->front) == (pQ->rear))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool out_queue(QUEUE *pQ, int *pVal)
{
	if(empty_queue(pQ))
	{
		return false;
	}
	else
	{
		*pVal = pQ->pBase[front]; 
		pQ->front = (pQ->front + 1) % 6;// front + 1取余6，使队首的索引取值范围保持在0~5，从而实现循环队列
		
		return true;
	}
}
