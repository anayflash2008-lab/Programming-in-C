#include <stdio.h>
#include<string.h>
int main() {
    char str[100], rev[100];
    int i;
    printf("Type the String you want to reverse :");
    fgets(str,sizeof(str),stdin);
    int j = strlen(str);

    for(i = 0; i < j; i++) {
        rev[i] = str[j - i - 1];
    }    
    rev[i] = '\0';
    printf("Reversed = %s", rev);
}