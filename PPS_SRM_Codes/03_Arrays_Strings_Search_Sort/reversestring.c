#include<stdio.h>
#include<string.h>
int main(void)
{
char st[30],cst[30];
printf("Enter a String?");
scanf("%[^\n]s",st);
//incorrect ->cst=st;
Correct Code:-> copy character by character
cst[0]=st[0]
cst[1]=st[1]
.
.
.
.
cst[6]=st[6] <- NULL
strrev(st);

//Incorrect -> if(st==cst)
To compare use strcmp
int d=strcmp(st,cst)
If both strings are same, then d=0
if both st and cst are placed in a dictionary
and st comes before cst, d will be negative
else
positive
printf("Reversed String is %s\n",st);
return 0;
}

