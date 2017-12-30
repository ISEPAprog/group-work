#include <stdio.h>
#include <stdlib.h>
#define MAX 30


typedef struct activity
{
    int id;
    int NC;
    float time;
}activity_type;

typedef struct student_team
{
    char name[21];
    int age;
    char sex;
    activity_type activity[6];
}student_type;

typedef struct team_prog
{
    char name[7];
    char locality[11];
    student_type student[9];
}team_type;

void showStudents (student_type student[], int qtd)
{
    int i;
    for (i=0;i<qtd;i++)
    {
        printf("\n---Student %d---\n",i+1);
        printf("%s\n",student[i].name);
        printf("%d\n",student[i].age);
        printf("%c\n",student[i].sex);
    }
}

//void

/*
Function to insert the students and save it to the structure.
*/

int insertStudent (student_type student[], int qtd)
{
    int i;
    for (i=0;i<qtd;i++)
    {
        printf("\n---Student %d---\n",i+1);
        fflush(stdin);
        printf("Student's name %d?\n",i+1);
        gets(student[i].name);
        fflush(stdin);
        do
        {
            printf("Student's age %d?\n",i+1);
            scanf("%d", &student[i].age);
            fflush(stdin);
        }while(student[i].age < 0 || student[i].age > 150);
        do
        {
            printf("Student's sex %d? (F/M)\n",i+1);
            scanf("%c", &student[i].sex);
            fflush(stdin);
        }while(student[i].sex != 'F' && student[i].sex != 'M');
    }
    return i;
}

int main()
{
    student_type student[MAX];
    int studentIndex;

    printf("Enter the number of students to save: ");
    scanf("%d", &studentIndex);
    insertStudent(student, studentIndex);
    showStudents(student, studentIndex);

    return 0;
}
