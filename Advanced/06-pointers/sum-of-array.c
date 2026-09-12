#include <stdio.h>
#define MAX_ARR 5
int main() {
    int ar[MAX_ARR] = {10,20,30,40,50};
    int i,sum = 0;
    int *p = ar;
    printf("The sum of ");
    for(i = 0; i < MAX_ARR; i++) {
        sum = sum + *(p+i);
        if(i == MAX_ARR - 1)
            printf("and %d = ",*(p+i));
        else if(i == MAX_ARR - 2)
            printf("%d ",*(p+i));
        else
         printf("%d , ",*(p+i));
    }
    printf("%d",sum);
}