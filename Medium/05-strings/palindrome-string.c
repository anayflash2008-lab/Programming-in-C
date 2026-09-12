#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, flag = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int j = strlen(str);

    if (str[j - 1] == '\n') {
        str[j - 1] = '\0';
        j--;
    }

    for (i = 0; i < j / 2; i++) {
        if (str[i] != str[j - i - 1]) {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}