#include <stdio.h>
int main() {
    int i,j;
    for(i = 1; i <= 2; i++) {
        printf("out : %d\n", i);
        for(j = 1; j<=3; ++j) {
            printf("inner : %d\n", j);
        }
    }
    return 0;
}