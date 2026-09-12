#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

int isEmpty()
{
    int flag = 0;

    if(top == -1)
        flag = 1;

    return flag;
}

int isFull()
{
    int flag = 0;

    if(top == MAX - 1)
        flag = 1;

    return flag;
}

void push()
{
    int x;
    if(isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &x);
    top++;
    stack[top] = x;
    printf("%d pushed into stack.\n", x);
}

void pop()
{
    int x;
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        return;
    }
    x = stack[top];
    top--;
    printf("%d popped from stack.\n", x);
}

void peek()
{
    if(isEmpty())
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element = %d\n", stack[top]);
}

void display()
{
    int i;
    if(isEmpty())
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    for(i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main()
{
    int ch;
    while(1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        if(ch == 1)
            push();
        else if(ch == 2)
            pop();
        else if(ch == 3)
            peek();
        else if(ch == 4)
            display();
        else
            printf("Invalid Choice\n");
    }
}