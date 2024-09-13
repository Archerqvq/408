/**
 * @file circular_queue.c
 * @author Archer
 * @version 1.0
 * @brief 
 * 
 * @date 2024-09-12
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct queue
{
    int *p_base;
    int front;
    int rear;
    int len;
    int cnt; // To record how many items in the queue right now
    int flag; // To record whether the queue is legal, aka whether the the queue is initialzed or not
}queue;

void queue_init(queue *q, int len); // Create len-1 items in the queue
bool is_queue_legal(queue *q);
bool is_queue_full(queue *q);
bool is_queue_empty(queue *q);
int queue_get_cnt(queue *q);
int queue_get_len(queue *q);
void enqueue(queue *q, int val);
void queue_traverse(queue *q);
int dequeue(queue *q);

int main(int argc, char *argv[])
{
    int i;
    queue q;

    queue_init(&q, 6);
    
    for(i = 0; i < q.len; i++)
    {
        enqueue(&q, i + 1);

        if(i == 3)
        {
            int queue_len = queue_get_len(&q);
            int queue_cnt = queue_get_cnt(&q);
            printf("When i equals 3 and len = %d, cnt = %d\n", queue_len, queue_cnt);
        }
    }   
    queue_traverse(&q);

    printf("cnt before queue traversal is %d\n", q.cnt);
    queue_traverse(&q);

    int cnt = q.cnt;
    for(i = 0; i < cnt; i++)
    {
        int ret_val = dequeue(&q);
        printf("The dequeued value is %d\n", ret_val);
        queue_traverse(&q);
    }

    return 0;
}

void queue_init(queue *q, int len)
{
    q->p_base = (int *)malloc(sizeof(int) * len);
    if(NULL == q->p_base)
    {
        printf("Memory allocation failed\n");
    }
    else
    {
        q->front = 0;
        q->rear = 0;
        q->cnt = 0;
        // By storing the amount of elements of len-1 to distinguish
        // a full queue or a empty queue    
        q->len = len; 
        q->flag = 1;
    }
}

bool is_queue_legal(queue *q)
{
    if(1 != q->flag)
    {
        printf("Plz initialize the queue before using it :(\n");
        return false;
    }
    else
    {
        return true;
    }
}

bool is_queue_full(queue *q)
{
    if(is_queue_legal(q))
    {
        int len = q->len;
        // By storing the amount of elements of len-1 to distinguish
        // a full queue or a empty queue
        if((q->rear + 1) % len == (q->front))
        {
            printf("The queue is full\n");
            return true;
        }
        else
        {
            return false;
        }         
    }
}

bool is_queue_empty(queue *q)
{
    if(is_queue_legal(q))
    {
        if(q->front == q->rear)
        {
            printf("The queue is empty\n");
            return true;                
        } 
        else
        {
            return false;
        }
    }
}

int queue_get_cnt(queue *q)
{
    if(is_queue_legal(q))
    {
        return (q->cnt);
    }
}

int queue_get_len(queue *q)
{
    if(is_queue_legal(q))
    {
        return (q->len);
    }
}

void enqueue(queue *q, int val)
{
    if(is_queue_legal(q) && !is_queue_full(q))
    {
        q->p_base[q->rear] = val;
        q->rear = (q->rear + 1) % 6;
        q->cnt++;
    }
}

void queue_traverse(queue *q)
{
    if(is_queue_legal(q) && !is_queue_empty(q))
    {
        int i = q->front;

        while(i != q->rear)
        {
            printf("%d  ", q->p_base[i]);
            i = (i + 1) % (q->len);
        }
        printf("\n");
    }    
}

int dequeue(queue *q)
{
    if(is_queue_legal(q) && !is_queue_empty(q))
    {
        int ret_val;

        ret_val = q->p_base[q->front];
        q->front = (q->front + 1) % q->len;
        q->cnt--;

        return ret_val;
    }
}