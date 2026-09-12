#include <stdio.h>
#include <string.h>

struct Employee{
    char empid[20];
    char name[20];
    float sal;
};

int main(){
    struct Employee a, *p;

    p = &a;

    printf("Enter Employee ID : ");
    scanf("%s", p->empid);

    printf("Enter Name of Employee : ");
    scanf("%s", p->name);

    printf("Enter Salary of the employee : ");
    scanf("%f", &p->sal);

    printf("\n--------------------------------- Details of Employee ---------------------------------\n");

    printf("Emp ID : %s\n", p->empid);
    printf("Employee Name : %s\n", p->name);
    printf("Salary : %.2f\n", p->sal);
}