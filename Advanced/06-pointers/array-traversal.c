#include <stdio.h>
int main() {
    int ar[10] = {12,34,543,23,94,482,25,830,735,1090};
    int i;
// printing first element of the Array
    //printf("%d\n", *ar);
//Printing second element of the array
   // printf("%d",*(ar+1));
    for(i = 0; i < 10; i++){
        printf("Number %d : %d\n",i+1,*(ar+i));
    }
    // Change the value of the first element to 13
    *ar = 13;

    // Change the value of the second element to 17
    *(ar+1) = 17;
}