#include<stdio.h>
int main(void)
{
char words[10][10]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
/*words[0]="ZERO"
words[0][0]='Z'*/
int num,d,t,s=0,f=0,c=0;
scanf("%d",&num);
if(num<0)
{
 printf("MINUS ");
 t=num*(-1);
}
else
 t=num;
int temp=t,nod=0;
while(temp>0)
{
 temp/=10;
 nod++;
}
//printf("There are %d digits in %d\n",nod,t);
while(t>0)
{
if(t%10!=0)
 f=1;
if((t%10==0)&&(f==0))
{
c++;
}
s=(s*10)+(t%10);
t/=10;
}
//printf("%d\n",s);
while(s>0)
{
d=s%10;
printf("%s ",words[d]);
s/=10;
}
for(int y=0;y<c;y++)
 printf(" ZERO");
printf("\n");
return 0;
}

