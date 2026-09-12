#include <stdio.h>

int palindrome_num(int n)
{
    int orig, rev = 0, rem, flag = 0;

    orig = n;

    for(; n != 0; n /= 10)
    {
        rem = n % 10;
        rev = rev * 10 + rem;
    }

    if(orig == rev)
        flag = 1;

    return flag;
}

int palindrome_str(char str[])
{
    int i, len, flag = 1;

    for(len = 0; str[len] != '\0'; len++);

    for(i = 0; i < len / 2; i++)
    {
        if(str[i] != str[len - i - 1])
        {
            flag = 0;
            break;
        }
    }

    return flag;
}

int main()
{
    int ch, n;
    char str[100];

    printf("1. Check Number Palindrome\n");
    printf("2. Check String Palindrome\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch(ch)
    {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &n);

            if(palindrome_num(n))
                printf("%d is a Palindrome.\n", n);
            else
                printf("%d is not a Palindrome.\n", n);

            break;

        case 2:
            printf("Enter a string: ");
            scanf("%s", str);

            if(palindrome_str(str))
                printf("%s is a Palindrome.\n", str);
            else
                printf("%s is not a Palindrome.\n", str);

            break;

    }

}