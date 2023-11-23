/**
 * @file stack_v2.c
 * @author Achar
 * @version 1.0
 * @brief Review
 * @date 2023-11-23
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX 3 // Stack's maximum size

// Functino declration
void push(void);
void pop(void);
void display(void);
void peek(void);
bool isFull(void);
bool isEmpty(void);

int stack[MAX];
int top = -1;

int main(void)
{
    int choice;
    printf("*** Stack Implementaion using Array ***");

    while (1)
    {
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
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            peek();
            break;
        }
        default:
        {
            printf("\nPlease Enter a Valid Choice: ");
            break;
        }
        }
    }

    return 0;
}

/**
 * @brief
 * @return true
 * @return false
 */
bool isFull(void)
{
    bool isStackFull = false;

    if (top >= (MAX - 1))
    {
        printf("\nStack overflow\n");
        isStackFull = true;
    }

    return (isStackFull);
}

/**
 * @brief
 */
bool isEmpty(void)
{
    bool isStackEmpty = false;

    if (top <= -1)
    {
        printf("\nStack underflow\n");
        isStackEmpty = true;
    }

    return (isStackEmpty);
}

/**
 * @brief
 */
void push(void)
{
    if (isFull() == false)
    {
        int value;
        printf("\nEnter a value to be pushed: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
    }
}

/**
 * @brief
 */
void pop(void)
{
    if (isEmpty() == false)
    {
        printf("\nThe popped elements is: %d \n", stack[top]);
        top--;
    }
}

/**
 * @brief
 */
void display(void)
{
    if (top > -1)
    {
        int i;
        printf("\n The elements in the stack are: \n");
        for (i = 0; i <= top; i++)
        {
            printf("%d  ", stack[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\n The Stack is empty\n");
    }
}

/**
 * @brief
 */
void peek(void)
{
    if (isEmpty() == false)
    {
        printf("\n The top element is %d\n", stack[top]);
    }
    else
    {
        printf("\n The Stack is empty\n");
    }
}