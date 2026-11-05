/*
st1[10]="SRM"
st2[10]="Hello"
st3[20]="SRMHello"
st3[0]=st1[0]
st3[1]=st1[1]
st3[2]=st1[2]
st3[3]=st2[0]
st3[4]=st2[1]
st3[5]=st2[2]
st3[6]=st2[3]
st3[7]=st2[4]
st3[8]=\x0
*/
#include<stdio.h>
int main(void)
{
int l,m;
char st1[60],st2[30],dummy;
scanf("%[^\n]s",st1);
scanf("%c",&dummy);
scanf("%[^\n]s",st2);
for(l=0;st1[l]!='\x0';l++);
for(m=0;st2[m]!='\x0';m++)
 st1[l+m]=st2[m];
st1[l+m]='\x0';
printf("The concantenated string is %s\n",st1);
return 0;
}
