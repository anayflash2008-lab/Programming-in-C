#include <stdio.h>
int main(){
    int a,b;
    int *x,*y,*z;
    printf("Enter number 1 : ");
    scanf("%d",&a);
    printf("Enter number 2 : ");
    scanf("%d",&b);
    printf("Original values of a and b are %d and %d respectively\n",a,b);
    x = &a;
    y = &b;
    *x = *z;
    *x = *y;
    *y = *z;
    printf("Final Values of a and b are %d,%d respectively",*x,*y);

}