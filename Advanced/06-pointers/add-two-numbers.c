#include <stdio.h>

int main() {
    // 2 integers a and b
    int a,b;
    printf("Enter number 1 : ");
    scanf("%d", &a);
    printf("Enter number 2 : ");
    scanf("%d",&b);
    // 2 pointers x and y
    int *x,*y;
    // Declare x and y as the addresses of a and b respectively
    x = &a;
    y = &b;
    // new variable c = pointer of x + pointer of y i.e value of a + value of b
    int c = *x + *y;
    printf("sum of %d and %d = %d",a,b,c);
}