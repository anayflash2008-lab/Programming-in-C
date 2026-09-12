#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TEACHER 3
#define MAX_STUDENT 3
struct Student {
    int rno;
    char name[20];
    int marks[3];
};

struct Teacher {
    int tno;
    char name[20];
    char mno[15];
};

struct College {
    struct Student students[3];
    struct Teacher teachers[2];
};

int main() {

    struct College c1;

    printf("===== ENTER STUDENT DETAILS =====\n");

    for(int i = 0; i < MAX_STUDENT; i++) {

        printf("\nStudent %d\n", i + 1);

        printf("Enter Roll No: ");
        scanf("%d", &c1.students[i].rno);

        printf("Enter Name: ");
        scanf("%s", c1.students[i].name);

        printf("Enter Marks in 3 Subjects: ");
        scanf("%d %d %d",&c1.students[i].marks[0],&c1.students[i].marks[1],&c1.students[i].marks[2]);
    }

    printf("\n===== ENTER TEACHER DETAILS =====\n");

    for(int i = 0; i < MAX_TEACHER; i++) {

        printf("\nTeacher %d\n", i + 1);

        printf("Enter Teacher ID: ");
        scanf("%d", &c1.teachers[i].tno);

        printf("Enter Name: ");
        scanf("%s", c1.teachers[i].name);

        printf("Enter Mobile Number: ");
        scanf("%s", c1.teachers[i].mno);
    }

    printf("\n\n===== COLLEGE RECORD =====\n");

    printf("\n--- STUDENTS ---\n");

    for(int i = 0; i < 3; i++) {

        printf("\nStudent %d\n", i + 1);
        printf("Roll No : %d\n", c1.students[i].rno);
        printf("Name    : %s\n", c1.students[i].name);

        printf("Marks   : ");
        for(int j = 0; j < 3; j++) {
            printf("%d ", c1.students[i].marks[j]);
        }

        int total = 0;
        float perc;

        for(int j = 0; j < 3; j++) {
            total += c1.students[i].marks[j];
        }

        printf("\nTotal   : %d\n", total);
        perc = total/3;
        printf("percentage : %.3f\n", perc);
    }

    printf("\n--- TEACHERS ---\n");

    for(int i = 0; i < 2; i++) {

        printf("\nTeacher %d\n", i + 1);
        printf("Teacher ID : %d\n", c1.teachers[i].tno);
        printf("Name       : %s\n", c1.teachers[i].name);
        printf("Mobile No  : %s\n", c1.teachers[i].mno);
    }
}