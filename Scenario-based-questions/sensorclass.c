#include <stdio.h>

int main()
{
    char c;
    printf("Enter token: ");
    scanf("%c", &c);
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
        printf("Office access granted\n");
        if (c == 'A' || c == 'E' || c == 'I' ||c == 'O' || c == 'U' ||c == 'a' || 
            c == 'e' || c == 'i' ||c == 'o' || c == 'u')
        {
            printf("It is a vowel");
        }
        else
        {
            printf("It is a consonant");
        }
    }
    else if (c >= '0' && c <= '9')
    {
        printf("Warehouse access granted");
    }
    else
    {
        printf("Access denied\n");
        printf("Security alert logged");
    }
}