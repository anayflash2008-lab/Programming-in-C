#include <stdio.h>
int fibo(int n){
    if(n == 1){
        return 1;
    }
    else if(n == 2){
        return 1;
    }
    else{
        return fibo(n-1) + fibo(n-2);
    }    
}
int main(){
    int fib;
    int n;
    scanf("%d",&n);
    fib = fibo(n);
    printf("%d",fib);
}