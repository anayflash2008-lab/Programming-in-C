#include <stdint.h>
#include <stdio.h>

int main() {
    int ar[5];
    int *a = ar;
    int i;
    for(i = 0; i<5; i++) {
        printf("enter number %d : ",i+1);
        scanf("%d", (a+i));
    } 

    for(i = 0; i<5; i++) {
        printf("Number %d : %d\n",i+1, *(a+i));
    }
}
