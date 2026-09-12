#include <stdio.h>
#include <string.h>
void reverse(char str[], int st, int end)
{
    int i, j;
    char temp;

    for(i = st, j = end; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
int main()
{
    char str[100];
    int i, start = 0, len;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);

    if(str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
        len--;
    }

    // Reverse whole string
    reverse(str, 0, len - 1);

    // Reverse each word
    for(i = 0; i <= len; i++)
    {
        if(str[i] == ' ' || str[i] == '\0')
        {
            reverse(str, start, i - 1);
            start = i + 1;
        }
    }

    printf("Reversed sentence: %s", str);
}