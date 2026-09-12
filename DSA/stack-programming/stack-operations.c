#include <stdio.h>

#define MAX 10
int push(int stack[], int top, int value) 
{
    if(top>= MAX - 1) 
    {
        printf("Stack Overflow\n");
        return top;
    }
    top++;
    stack[top] = value;
    printf("%d pushed to stack\n", value);
    return top;
}
int pop(int stack[], int top)
{
    if (top == -1)
    {
        printf("Stack Underflow! Stack is empty.\n");
        return top;
    }
    printf("%d popped from the stack.\n", stack[top]);
    top--;
    return top;
}
void display(int stack[], int top)
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}
int main()
{
    int stack[MAX];
    int top = -1;
    int ch, val;

    while (1)
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                top = push(stack, top, val);
                break;
            case 2:
                top = pop(stack, top);
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}