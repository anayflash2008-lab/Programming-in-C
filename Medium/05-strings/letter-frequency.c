#include <stdio.h>
#include <string.h>

int main() {
    char str[100], a;
    int cnt, len;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);

    for (a = 'a'; a <= 'z'; a++) {
        cnt = 0;

        for (int i = 0; i < len; i++) {
            char ch = str[i];

            if (ch >= 'A' && ch <= 'Z')
                ch = ch + ('a'-'A');

            if (ch == a)
                cnt++;
        }

        if (cnt > 0)
            printf("%c = %d\n", a, cnt);
    }

    return 0;
}