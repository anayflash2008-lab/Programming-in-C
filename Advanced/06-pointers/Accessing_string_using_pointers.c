#include <stdio.h>
int main()
{
    int i;
    char st[100];
    char *p = st;
    printf("Enter a string: ");
    scanf("%[^\n]s", st);
    for(i = 0; *p != '\0'; i++, p++)
    {
        printf("%c", *p);
    }
    return 0;
}