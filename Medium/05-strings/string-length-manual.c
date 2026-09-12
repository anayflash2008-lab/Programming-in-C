#include <stdio.h>
int main() {
    char st[] = "Hello World";
    int length = 0;
    //printf("%s",st[]);    
    while(st[length] != '\0') {
        length++;
    }

    printf("Length = %d", length);

}
