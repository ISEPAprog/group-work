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

char form()
{
    char r;
    do
    {
        printf("---Main menu---\n");
        printf("1- Manage students.\n");
        printf("2- Manage activities.\n");
        printf("3- Manage teams.\n");
        printf("4- In progress.\n");
        printf("5- In progress.\n");
        printf("s/S- Preencher estruturas.\n");
        r=getch();
    }
    while (r!='s' && r!='S' && r!='1' && r!='2' && r!='3' && r!='4' && r!='5');
    return r;
}

char formStudents()
{
    char r;
    do
    {
        printf("---Student Section---\n");
        printf("1- Insert a new student.\n");
        printf("2- Show students.\n");
        printf("3- Delete a student.\n");
        printf("4- Search a student.\n");
        printf("r/R- Return to menu.\n");
        r=getch();
    }
    while (r!='r' && r!='R' && r!='1' && r!='2' && r!='3' && r!='4');
    return r;
}

char formActivity()
{
    char r;
    do
    {
        printf("---Activity Section---\n");
        printf("1- Insert a new activity.\n");
        printf("2- Show activities.\n");
        printf("3- Delete an activity.\n");
        printf("4- Search an activity.\n");
        printf("r/R- Return to menu.\n");
        r=getch();
    }
    while (r!='r' && r!='R' && r!='1' && r!='2' && r!='3' && r!='4');
    return r;
}

char formTeam()
{
    char r;
    do
    {
        printf("---Team Section---\n");
        printf("1- Insert a new team.\n");
        printf("2- Show teams.\n");
        printf("3- Delete a team.\n");
        printf("4- Search a team.\n");
        printf("r/R- Return to menu.\n");
        r=getch();
    }
    while (r!='r' && r!='R' && r!='1' && r!='2' && r!='3' && r!='4');
    return r;
}

char formTeamMan()
{
    char r;
    do
    {
        printf("---Team Section---\n");
        printf("1- Insert a new team.\n");
        printf("2- Show teams.\n");
        printf("3- Delete a team.\n");
        printf("4- Search a team.\n");
        printf("r/R- Return to menu.\n");
        r=getch();
    }
    while (r!='r' && r!='R' && r!='1' && r!='2' && r!='3' && r!='4');
    return r;
}

int main()
{
    student_type student[MAX];
    int studentIndex;
    char ch;

    /*printf("Enter the number of students to save: ");
    scanf("%d", &studentIndex);
    insertStudent(student, studentIndex);
    showStudents(student, studentIndex);*/
    do
    {
        ch = form();
        switch(ch)
        {
            case '1':
                {//Manage students info
                    do
                    {
                        ch = formStudents();
                        switch(ch)
                        {
                            case '1':
                                { //insert new students
                                break;
                                }
                            case '2':
                                { //show students
                                break;
                                }
                            case '3':
                                { //delete student
                                break;
                                }
                            case '4':
                                { //search student
                                break;
                                }
                        }
                    } while(ch!='r' && ch!='R');
                    break;
                }
            case '2':
                { //manage activity info
                do
                    {
                        ch = formActivity();
                        switch(ch)
                        {
                            case '1':
                                { //insert new activity
                                break;
                                }
                            case '2':
                                { //show activities
                                break;
                                }
                            case '3':
                                { //delete activities
                                break;
                                }
                            case '4':
                                { //search activities
                                break;
                                }
                        }
                    } while(ch!='r' && ch!='R');
                break;
                }
            case '3':
                {// Team management
                do
                    {
                        ch = formTeam();
                        switch(ch)
                        {
                            case '1':
                                { //insert new team
                                break;
                                }
                            case '2':
                                { //show teams (alphabetically sorted)
                                break;
                                }
                            case '3':
                                { //delete team
                                break;
                                }
                            case '4':
                                { //search teams and give option to show the elements
                                break;
                                }
                        }
                    } while(ch!='r' && ch!='R');
                break;
                }
            case '4':
                { //Teams info
                do
                    {
                        ch = formTeamMan();
                        switch(ch)
                        {
                            case '1':
                                { //total and average right answers of a team
                                break;
                                }
                            case '2':
                                { //average age
                                break;
                                }
                            case '3':
                                { //less time wasted per activity
                                break;
                                }
                        }
                    } while(ch!='r' && ch!='R');
                break;
                }
            case '5':
                { //ordenar por idade
                //ordenarPorIdade(aluno,qtd);
                getch(); break;
                }
        }
    } while(ch!='s' && ch!='S');

 return 0;
}
