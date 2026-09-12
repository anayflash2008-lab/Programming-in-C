#include <stdio.h>

int main() {
// Reverse array using pointers
    int ar[5] = {10,20,30,40,50};
    int i, temp;
    int *p = ar;
    int len = sizeof(ar) / sizeof(ar[0]);

    for(i = 0; i < len / 2; i++) {
        temp = *(p + i);
        *(p + i) = *(p + len - i - 1);
        *(p + len - i - 1) = temp;
    }

    for(i = 0; i < len; i++) {
        printf("%d ", *(p + i));
    }

    return 0;
}