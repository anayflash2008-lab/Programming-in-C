#include <stdio.h>
#include <string.h>

int add(int a, int b){
    int c = a+b;
   // printf("\n%d",c);
    return c;
}
int main(){
    int c,d,e;
    c = add(1055,20);
    d = add(20,30);    
    e = c + d;
     printf("\n c= %d , d = %d e = %d",c,d,e);
}