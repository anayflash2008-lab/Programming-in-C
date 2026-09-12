//Modify Variable Using Pointer
#include <stdio.h>

int main() {

    int a = 5;
    int *b;
    b = &a; 
    *b = 20;

    printf("%d", a);
}