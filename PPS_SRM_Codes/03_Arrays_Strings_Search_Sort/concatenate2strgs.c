/*
st1="SRM"
st2="Hi"
st3="SRMHi"
st3[0]=st1[0]
st3[1]=st1[1]
st3[2]=st1[2]
st3[3]=st2[0]
st3[4]=st2[1]
st3[5]='\x0'
*/
#include<stdio.h>
int main(void)
{
char st1[30],st2[30],st3[60],dummy;
int l,m;
scanf("%[^\n]s",st1);
scanf("%c",&dummy);
scanf("%[^\n]s",st2);
for(l=0;st1[l]!='\x0';l++)
 st3[l]=st1[l];
for(m=0;st2[m]!='\x0';m++)
 st3[l+m]=st2[m];
st3[l+m]='\x0';
printf("The concatenated string is %s\n",st3);
return 0;
}

