#include <stdio.h>
int main(){
    int arr[5] = {10,20,30,40,50};
    int *p = arr;
    int max = *p;

    for(int i = 0; i < 5; i++) {
        if (*(p+i) > max){
            max = *(p+i);
        }
    }
    printf("the largest element is : %d\n ", max);
}
