// date: 22-01-2024 - by lin
// Check
// https://embetronicx.com/tutorials/p_language/c/stack-data-structure-in-c-programming/
// for more information.
#include <stdio.h>
#include <stdbool.h>

#define MAX 3 // Stack's maximum size

// Function declaration
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
    printf("*** Stack Implementation using Array ***");

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
            printf("\nPlease Enter a Valid Choice: ");
            break;
        }
        }
    }

    return 0;
}

bool isFull(void)
{
    bool isStackFull = false;

    if ((MAX - 1) <= top)
    {
        printf("\nStack overflow\n");
        isStackFull = true;
    }

    return isStackFull;
}

bool isEmpty(void)
{
    bool isStackEmpty = false;

    if (-1 >= top)
    {
        printf("\nStack underflow\n");
        isStackEmpty = true;
    }

    return isStackEmpty;
}

void push(void)
{
    if (false == isFull())
    {
        int value;
        printf("\nEnter a value to be pushed:");
        scanf("%d", &value);
        top++;
        stack[top] = value;
    }
}

void pop(void)
{
    if (false == isEmpty())
    {
        printf("\nThe popped element is: %d\n", stack[top]);
        top--;
    }
}

void display(void)
{
    if (-1 < top)
    {
        int i;
        printf("\nThe elements in the stack are: \n");
        for (i = 0; i <= top; i++)
        {
            printf("%d  ", stack[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\nThe Stack is empty\n");
    }
}

void peek(void)
{
    if (-1 < top)
    {
        printf("\nThe top element is %d\n", stack[top]);
    }
    else
    {
        printf("\nThe Stack is empty\n");
    }
}
