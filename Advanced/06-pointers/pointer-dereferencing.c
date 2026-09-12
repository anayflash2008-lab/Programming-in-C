#include <stdio.h>
#include <string.h>
int main() {
    int a = 10;
    // declare a pointer 
    int *b;
    // store address of a in b 
    b = &a;
    // print address of a and value of a using pointer b
    printf("b = %x value of a = %d",b,*b);

}