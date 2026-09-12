#include <stdio.h>

struct Student {
  int rno;
  char name[20];
  int marks[3];
};

int main() {
  struct Student a;
  printf("Enter roll number : ");
  scanf("%d",&a.rno);
  printf("Enter name : ");
  scanf("%s",a.name);
  //fgets(a.name,sizeof(a.name),stdin);
  printf("Enter marks PCM :");
  scanf("%d %d %d",&a.marks[0],&a.marks[1],&a.marks[2]);
  printf("--------------------------------------------------------------------------------------\n");
  printf("Student %s's roll number : %d\n name : %s\n Marks of Math : %d , Physics : %d , Chemistry : %d",a.name,a.rno,a.name
    ,a.marks[0],a.marks[1],a.marks[2]);


  return 0;
}