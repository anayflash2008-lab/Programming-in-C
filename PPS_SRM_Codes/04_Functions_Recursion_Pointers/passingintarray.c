#include<stdio.h>
int main(void)
{
int a[5]={1,2,3,8},s=sizeof(a)/sizeof(int);
void print(int *);
printf("In main() %d:\n",s);
for(int i=0;i<4;i++)
 printf("%d\n",a[i]);
print(&a[0]);
return 0;
}
void print(int *p)
{
int i;
for(i=0;i<4;i++,p++)
 printf("%d\n",*p);
p--;
i--;
while(i>=0)
{
printf("%d\n",*p);
p--;
i--;
}
}
