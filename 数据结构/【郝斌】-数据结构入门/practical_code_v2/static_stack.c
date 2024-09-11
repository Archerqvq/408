/**
 * @file static_stack.c
 * @author Archer
 * @version 1.0
 * @brief 
 * based on https://embetronicx.com/tutorials/p_language/c/stack-data-structure-in-c-programming/
 * 
 * @date 2024-09-11
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 3 // Stack's maximum size

void push(void);
void pop(void);
void display(void);
void peek(void);
bool is_full(void);
bool is_empty(void);

int stack[MAX_SIZE];
int top = -1;

int main(int argc, char **argv)
{
    int choice;
    printf("*** Stack Implementation using array ***");

    while(1)
    {
        printf("\n====================================");
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Elements\n");
        printf("4. Peek Top element\n");
        printf("Enter the Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                // Pushing(Inserting) the element into the stack
                push();
                break;
            }
            case 2:
            {
                // Poping(Removing) the element into the stack
                pop();
                break;
            }
            case 3:
            {
                // Display all the elements in the stack
                display();
                break;
            }
            case 4:
            {
                // Display the last element which is pushed into the stack
                peek();
                break;
            }
            default:
            {
                printf("\nPlease enter a valid choice: ");
                break;
            }
        }        
    }

    return 0;
}

bool is_full(void)
{
    bool is_overflow = false;

    if((MAX_SIZE - 1) == top)
    {
        printf("Stack overflow\n");
        is_overflow = true;
    }

    return is_overflow;
}

bool is_empty(void)
{
    bool is_underflow = false;

    if(-1 == top)
    {
        printf("Stack underflow\n");
        is_underflow = true;
    }

    return is_underflow;
}

void push(void)
{
    if(!is_full())
    {
        int val;
        printf("Enter a value to be pushed: ");
        scanf("%d", &val);
        top++;
        stack[top] = val;
    }
}

void pop(void)
{
    if(!is_empty())
    {
        printf("The popped element is: %d\n", stack[top]);
        top--;
    }
}

void display(void)
{
    if(-1 < top)
    {
        int i;
        printf("The elements in the stack are: \n");
        
        for(i = 0; i <= top; i++)
        {
            printf("%d  ", stack[i]);
        }
        printf("\n");
    }
    else
    {
        printf("The stack is empty\n");
    }
}

void peek(void)
{
    if(-1 < top)
    {
        printf("The top element is %d\n", stack[top]);
    }
    else
    {
        printf("The stack is empty\n");
    }
}

