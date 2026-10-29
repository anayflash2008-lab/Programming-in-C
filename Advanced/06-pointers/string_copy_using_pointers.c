#include <stdio.h>

int main(){
    int i;
    char st1[100];
    char st2[100];
    char *p = st1;
    char *q = st2;

    printf("Enter a string: ");
    if(scanf("%99[^\n]", st1) != 1)
        return 1;

    for(i = 0; *p != '\0'; i++, *p++, *q++){
        *q = *p;
    }

    *q = '\0';

    q = st2;

    for(i = 0; *q != '\0'; i++, *q++){
        printf("%c", *q);
    }

    return 0;
}