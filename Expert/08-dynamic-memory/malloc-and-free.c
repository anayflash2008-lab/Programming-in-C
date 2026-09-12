#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
    int n;
    
    printf("Enter n : ");
    scanf("%d",&n);
    int *b; // ptr which will hold n location in heap me
    b = (int *) malloc(sizeof(int) * n); // n dynamic memory  

   for(int i = 0; i < n; i++){
         b[i] = rand() * i;
         printf("Value at the position %d : %d\n",i+1,b[i]);    
    }
    free(b); // deallocate memory 


}