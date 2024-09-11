/**
 * @file dynamic_stack.c
 * @author Archer
 * @version 1.0
 * @brief 
 * 
 * @date 2024-09-11
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR (0xFFFF)

typedef struct node
{
    int data; // Data area
    struct node *p_next; // Pointer area
}node, *p_node;

typedef struct stack
{
    p_node top;
    p_node bottom;
}stack, *p_stack;

void stack_init(p_stack *s);
void stack_push(p_stack s, int val);
int stack_pop(p_stack s);
void stack_traverse(p_stack s);
bool is_stack_empty(p_stack s);
void stack_clear(p_stack s);

int main(int argc, char **argv)
{
    p_stack s;

    stack_init(&s);
    stack_push(s, 1);
    stack_push(s, 2);
    stack_push(s, 3);
    stack_traverse(s);

    int ret_val = stack_pop(s);
    printf("The popped value is %d\n\n", ret_val);
    stack_traverse(s);

    ret_val = stack_pop(s);
    printf("The popped value is %d\n\n", ret_val);
    stack_traverse(s);

    ret_val = stack_pop(s);
    printf("The popped value is %d\n\n", ret_val);
    stack_traverse(s);

    ret_val = stack_pop(s);

    stack_push(s, 1);
    stack_push(s, 2);
    stack_push(s, 3);
    stack_traverse(s);
    stack_clear(s);
    stack_traverse(s);

    return 0;
}

void stack_init(p_stack *s)
{    
    // ! ATTENTION: 
    // ! The memory allocation of stack is needed
    // ! Can't without the statement below before initialzing the head node
    *s = (p_stack)malloc(sizeof(stack));

    if(NULL == *s)
    {
        printf("Memory allocation failed\n");
        exit(-1); // Exit the program
    }

    // Create a head node after the stack memory allocation but the data area doesn't store things
    (*s)->top = (p_node)malloc(sizeof(node));
    (*s)->bottom = (*s)->top;
    (*s)->bottom->p_next = NULL;
}

void stack_push(p_stack s, int val)
{
    p_node new = (p_node)malloc(sizeof(node));

    if(NULL == new)
    {
        printf("Memory allocation failed\n");
        exit(-1);
    }

    new->data = val;
    new->p_next = s->top;
    s->top = new;
}

bool is_stack_empty(p_stack s)
{
    if(s->top == s->bottom)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void stack_traverse(p_stack s)
{
    if(!is_stack_empty(s))
    {
        p_node p = s->top;

        printf("The stack's nodes are printed from top to bottom below: \n");
        while(p != s->bottom)
        {
            printf("%d  ", p->data);
            p = p->p_next;
        }
        printf("\n");
    }
    else
    {
        printf("The stack is empty, so there's no need to traverse\n");
    }
}

int stack_pop(p_stack s)
{
    if(is_stack_empty(s))
    {
        printf("The stack is empty, there's no node in the stack needed to pop\n");
        return ERROR;
    }
    else
    {
        int ret_val = 0;
        p_node p = s->top;

        ret_val = p->data;
        s->top = p->p_next;
        free(p);

        return ret_val;
    }
}

void stack_clear(p_stack s)
{
    if(is_stack_empty(s))
    {
        printf("The stack is empty, there's no need to clear\n");
    }
    else
    {
        p_node p;

        while(s->top != s->bottom)
        {
            p = s->top;
            s->top = p->p_next;
            free(p); // Free every memory of node in the stack to avoid memory leak
        }

        s->top = s->bottom;

        printf("All nodes in the stack are clear\n");
    }
}
