#include <stdio.h>
int nod(int n){
    int t;
    if(n == 0){
        return 0;
    }
    else{
        t = 1 + nod(n/10);
    }
}
int main(){
    int n,t;
    scanf("%d",&n);
    t = nod(n);
    printf("%d",t);
}