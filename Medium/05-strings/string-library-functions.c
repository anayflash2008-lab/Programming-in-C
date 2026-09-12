#include <stdio.h>
#include <string.h>
int main() {
//Length of string using strlen()
    char str[] = "Hello World";
    printf("%zu \n",strlen(str));
//Concatenate strings
    char str2[] = "Hii people";
    strcat(str,str2);
    printf("%s,%s",str,str2);
}