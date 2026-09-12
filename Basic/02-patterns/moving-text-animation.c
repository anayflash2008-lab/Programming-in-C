#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_ARR 100
int main() {
    int i;
   
    for(i = 0; i < MAX_ARR; i++) {
        system("cls");
        for(int j=0;j<i;j++){
            printf("\n");
             }
        for(int j=0;j<i;j++){
            printf(" ");
             }
        
             printf("    ANAY ");
             Sleep(15);
    }
}