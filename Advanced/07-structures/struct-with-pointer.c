#include <stdio.h>

struct Student {
  int rno;
  char name[20];
  int marks[3];
};

int main() {
  struct Student a,*p;
  p = &a;
  printf("Enter roll number : ");
  scanf("%d",&p->rno);
  printf("Enter name : ");
  scanf("%s",p->name);
  printf("Enter marks PCM :");
  scanf("%d %d %d",&p->marks[0],&p->marks[1],&p->marks[2]);
  printf("----------------------------------------------------------------------------------------------\n");
  printf("Student %s's roll number : %d\n name : %s\n Marks of Math : %d , Physics : %d , Chemistry : %d",p->name,p->rno,p->name
    ,p->marks[0],p->marks[1],p->marks[2]);
  float per;
  per = (p->marks[0] + p->marks[1] + p->marks[2]) / 3.0;

  printf("\nPercentage = %.2f%%", per);

}