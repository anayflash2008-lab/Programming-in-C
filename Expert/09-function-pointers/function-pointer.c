#include <stdio.h>

int add(int a, int b) {
    int c;
    c = a+b;
    return c;
}

int main() {
    int (*ptr)(int, int);
    ptr = add;
    printf("%d", ptr(5, 3));
    return 0;
}