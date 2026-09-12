#include <stdio.h>
void draw(int n,int i) {
    int j;
    for(j = 1; j <= n - i ; j++) {
                printf(" ");
            }
            for(j = 1; j <= i; j++) {
            
                printf(" *");
            }
}
int main() {
    int n;
    int i,j;
    printf("enter the number till the series will go on :" );
    scanf("%d",&n);
    for(i = 1; i <= n; i++) {
        //printf("%d",i);
        draw(n,i);
            printf("\n");
        }
        for(i = n-1; i >= 1; i--) {
          //  printf("%d",i);
        
            draw(n,i);
            printf("\n");
        }
}