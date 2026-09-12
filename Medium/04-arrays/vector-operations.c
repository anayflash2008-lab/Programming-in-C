#include <stdio.h>

void addition(int a[], int b[], int c[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        c[i] = a[i] + b[i];
    printf("A + B = ");
    for(i = 0; i < n; i++)
        printf("%d ", c[i]);
    printf("\n");
}

void subtraction(int a[], int b[], int c[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        c[i] = a[i] - b[i];
    printf("A - B = ");
    for(i = 0; i < n; i++)
        printf("%d ", c[i]);
    printf("\n");
}

int dotProduct(int a[], int b[], int n)
{
    int i, dot = 0;
    for(i = 0; i < n; i++)
        dot = dot + a[i] * b[i];
    return dot;
}

void crossProduct(int a[], int b[], int c[])
{
    c[0] = a[1] * b[2] - a[2] * b[1];
    c[1] = a[2] * b[0] - a[0] * b[2];
    c[2] = a[0] * b[1] - a[1] * b[0];
    printf("A x B = (%d, %d, %d)\n",
           c[0], c[1], c[2]);
}

int main()
{
    int a[100], b[100], c[100];
    int n, i, ch = 0;
    printf("Enter size of vectors: ");
    scanf("%d", &n);
    printf("Enter Vector A:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter Vector B:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &b[i]);

    while(ch != 5)
    {
        printf("\n===== VECTOR MENU =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Dot Product\n");
        printf("4. Cross Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                addition(a, b, c, n);
                break;

            case 2:
                subtraction(a, b, c, n);
                break;

            case 3:
                printf("Dot Product = %d\n",
                       dotProduct(a, b, n));
                break;

            case 4:
                if(n == 3)
                    crossProduct(a, b, c);
                else
                    printf("Cross product requires 3D vectors.\n");
                break;

            case 5:
                printf("Exiting\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    }
}