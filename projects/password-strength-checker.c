#include <stdio.h>
#include <math.h>

int getCharacterSetSize(char password[])
{
    int hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;
    int charset = 0;

    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
            hasLower = 1;
        else if (password[i] >= 'A' && password[i] <= 'Z')
            hasUpper = 1;
        else if (password[i] >= '0' && password[i] <= '9')
            hasDigit = 1;
        else
            hasSpecial = 1;
    }

    if (hasLower)
        charset += 26;

    if (hasUpper)
        charset += 26;

    if (hasDigit)
        charset += 10;

    if (hasSpecial)
        charset += 32;

    return charset;
}

void prob(char pass[])
{
    int i, len = 0;
    double cs, probab;

    for (i = 0; pass[i] != '\0'; i++)
        len++;

    cs = getCharacterSetSize(pass);

    printf("\nLength = %d\n", len);
    printf("Character Set Size = %.0lf\n", cs);

    probab = 1.0 / pow(cs, len);

    printf("Probability of guessing this password in one random attempt = %.10e\n", probab);
}

int main()
{
    char pass[100];
    int i = 0;
    int len = 0;
    int up = 0, low = 0, dig = 0, special = 0;
    int score = 0;

    printf("Enter Password: ");
    scanf("%99s", pass);

    while (pass[i] != '\0')
    {
        len++;

        if (pass[i] >= 'A' && pass[i] <= 'Z')
            up = 1;

        else if (pass[i] >= 'a' && pass[i] <= 'z')
            low = 1;

        else if (pass[i] >= '0' && pass[i] <= '9')
            dig = 1;

        else
            special = 1;

        i++;
    }

    printf("\nPassword Analysis\n");
    printf("-----------------\n");

    if (len >= 8)
    {
        printf("Minimum Length : Yes\n");
        score++;
    }
    else
        printf("Minimum Length : No\n");

    if (up)
    {
        printf("Uppercase      : Yes\n");
        score++;
    }
    else
        printf("Uppercase      : No\n");

    if (low)
    {
        printf("Lowercase      : Yes\n");
        score++;
    }
    else
        printf("Lowercase      : No\n");

    if (dig)
    {
        printf("Digit          : Yes\n");
        score++;
    }
    else
        printf("Digit          : No\n");

    if (special)
    {
        printf("Special Char   : Yes\n");
        score++;
    }
    else
        printf("Special Char   : No\n");

    printf("\nStrength: ");

    if (score <= 2)
        printf("Weak\n");
    else if (score <= 4)
        printf("Medium\n");
    else
        printf("Strong\n");

    prob(pass);

}