#include <stdio.h>

int main() {
    char str[] = "Hello";
    char *p = str;
    int count;

    for(count = 0; *p != '\0'; p++) {
        count++;
    }

    printf("Length = %d\n", count);

    return 0;
}