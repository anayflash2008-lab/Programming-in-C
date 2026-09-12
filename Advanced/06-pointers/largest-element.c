#include <stdio.h>

int main() {
    int arr[] = {5, 19, 22, 15, 7};
    int *p = arr;
    int max = *p;

    for(int i=1; i<5; i++) {
        if(*(p+i) > max) {
            max = *(p+i);
        }
    }

    printf("Largest = %d\n", max);

    return 0;
}