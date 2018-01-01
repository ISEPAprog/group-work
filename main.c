#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

/*
Function to insert the students and save it to the structure.
*/

int insertStudent (student_type student[], int oldStudentIndex, int newStudentIndex)
{
    int i;
    for (i=oldStudentIndex;i<newStudentIndex;i++)
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

int deleteStudent(student_type student[], char studentToDelete[], int newStudentIndex)
{
    int i;

    for(i = 0; i < newStudentIndex; i++)
    {
        if(!strcmp(student[i].name,studentToDelete))
        {
            while(i < newStudentIndex-1)
            {
                strcpy(student[i].name,student[i+1].name);
                student[i].age = student[i+1].age;
                student[i].sex = student[i+1].sex;
                i++;
            }
            student[i].name[0] = '\0';
            student[i].age = 0;
            student[i].sex = 0;
        }
    }
    return i-1;
}

int insertActivity (activity_type activity[], int oldActivityIndex, int newActivityIndex)
{
    int i;
    for (i=oldActivityIndex;i<newActivityIndex;i++)
    {
        printf("\n---Activity %d---\n",i+1);
        fflush(stdin);
        do
        {
            printf("Activity's ID %d?\n",i+1);
            scanf("%d", &activity[i].id);
            fflush(stdin);
        }while(activity[i].id < 0);
        do
        {
            printf("Correct answers of activity %d?\n",i+1);
            scanf("%d", &activity[i].NC);
            fflush(stdin);
        }while(activity[i].NC < 0);
        do
        {
            printf("Time in minutes for activity %d?\n",i+1);
            scanf("%f", &activity[i].time);
            fflush(stdin);
        }while(activity[i].time < 0);
    }
    return i;
}

void showActivities (activity_type activity[], int qtd)
{
    int i;
    for (i=0;i<qtd;i++)
    {
        printf("\n---Activity %d---\n",i+1);
        printf("%d\n",activity[i].id);
        printf("%d\n",activity[i].NC);
        printf("%.2f\n",activity[i].time);
    }
}

int deleteActivity(activity_type activity[], int activityToDelete, int newActivityIndex)
{
    int i;

    for(i = 0; i < newActivityIndex; i++)
    {
        if(activity[i].id == activityToDelete)
        {
            while(i < newActivityIndex-1)
            {
                activity[i].id = activity[i+1].id;
                activity[i].NC = activity[i+1].NC;
                activity[i].time = activity[i+1].time;
                i++;
            }
            activity[i].id = 0;
            activity[i].NC = 0;
            activity[i].time = 0;
            printf("\nThe activity with the ID: %d is deleted.\n", activityToDelete);
        }
    }
    return i-1;
}

char form()
{
    char r;
    do
    {
        printf("\n---Main menu---\n");
        printf("1- Manage students.\n");
        printf("2- Manage activities.\n");
        printf("3- Manage teams.\n");
        printf("4- In progress.\n");
        printf("5- In progress.\n");
        printf("s/S- Exit.\n");
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
        printf("\n---Student Section---\n");
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
        printf("\n---Activity Section---\n");
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
        printf("\n---Team Section---\n");
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
        printf("\n---Team Section---\n");
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
    activity_type activity[100];
    int oldStudentIndex = 0, newStudentIndex = 0, studentsToInsert = 0;
    char studentToDelete[21];
    int oldActivityIndex = 0, newActivityIndex = 0, activitiesToInsert = 0;
    int activityToDelete = 0;
    char ch;

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
                                {
                                    //insert new student
                                    printf("Enter the number of students to save: ");
                                    scanf("%d", &studentsToInsert);
                                    newStudentIndex = oldStudentIndex + studentsToInsert;
                                    oldStudentIndex = insertStudent(student, oldStudentIndex, newStudentIndex);
                                    break;
                                }
                            case '2':
                                {
                                    //show student
                                    showStudents(student, newStudentIndex);
                                    break;
                                }
                            case '3':
                                {
                                    //delete student
                                    printf("Enter the student's name to delete: ");
                                    gets(studentToDelete);
                                    newStudentIndex = deleteStudent(student, studentToDelete, newStudentIndex);
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
                                {
                                    //insert activity
                                    printf("Enter the number of activities to save: ");
                                    scanf("%d", &activitiesToInsert);
                                    newActivityIndex = oldActivityIndex + activitiesToInsert;
                                    oldActivityIndex = insertActivity(activity, oldActivityIndex, newActivityIndex);
                                    break;
                                }
                            case '2':
                                {
                                    //show activity
                                    showActivities(activity, newActivityIndex);
                                    break;
                                }
                            case '3':
                                {
                                    //delete activity
                                    printf("Enter the activity's ID to delete: ");
                                    scanf("%d", &activityToDelete);
                                    newActivityIndex = deleteActivity(activity, activityToDelete, newActivityIndex);
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
                                    //insertTeam(team, )

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
