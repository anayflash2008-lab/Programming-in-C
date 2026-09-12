#include <stdio.h>
#include <string.h>

int char_count(char a , char str[]){
    int cnt = 0;
    int len = strlen(str);
    for(int i = 0; i<= len; i++){
        if(a == str[i]){
            cnt++;
        }

    }
    return cnt;
}

int main() {
    char str[100], a;
    int cnt, len;
    char lookup[100];

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    len = strlen(str);
    for(int i = 0; i<= len; i++){
    a = str[i];
    cnt = char_count(a,str);
    printf("%c = %d\n", a, cnt);
    
  }
}
