#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
#define NR 30

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


int teamInd, studInd[100], actInd[100];


/*
Function to insert the students and save it to the structure.
*/

int insertStudent (team_type team[], int oldStudentIndex, int newStudentIndex, char teamToInsert[])
{
    if(newStudentIndex >= 8)
    {
        printf("Warning: you can enter at least 8 students.");
        return newStudentIndex;
    }

    int i,j,teamLength;
    teamLength = 100;
    for(i = 0; i < teamLength; i++)
    {
        if(!strcmp(team[i].name,teamToInsert))
        {
            j = i;
            break;
        }
    }

    for (i=oldStudentIndex;i<newStudentIndex;i++)
    {
        printf("\n---Student %d---\n",i+1);
        fflush(stdin);
        printf("Student's name %d?\n",i+1);
        gets(team[j].student[i].name);
        fflush(stdin);
        do
        {
            printf("Student's age %d?\n",i+1);
            scanf("%c", &team[j].student[i].name);
            fflush(stdin);
        }while(team[j].student[i].age < 0 || team[j].student[i].age > 150);
        do
        {
            printf("Student's sex %d? (F/M)\n",i+1);
            scanf("%c", &team[j].student[i].sex);
            fflush(stdin);
        }while(team[j].student[i].sex != 'F' && team[j].student[i].sex != 'M');
    }
    return i;


}

void showStudents (team_type team[], int qtd)
{
    int i,j;
    for (i=0;i<qtd;i++)
    {
        printf("\n****** Team %d ******\n\n",i+1);
        for(j = 0; j < 8; j++)
        {
            printf("--- Student %d ---\n", j+1);
            printf("Name: \t%s\n",team[i].student[j].name);
            printf("Age: \t%d\n",team[i].student[j].age);
            printf("Gender: %c\n\n",team[i].student[j].sex);
            /*for(k = 0;k < 5; k++)
            {
                printf("%d\n",team[i].student[j].activity[k].id);
                printf("%d",team[i].student[j].activity[k].NC);
                printf("",team[i].student[j].activity[k].time);
            }*/
        }
    }
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
/*
int insertTeam (team_type team[],student_type student[], int oldTeamIndex, int newTeamIndex)
{
    int i,j,k,studentsToAdd;
    char nameToAdd[21];
    for (i=oldTeamIndex;i<newTeamIndex;i++)
    {
        printf("\n---Team %d---\n",i+1);
        fflush(stdin);
        printf("Team's name %d?\n",i+1);
        gets(team[i].name);
        fflush(stdin);
        gets(team[i].locality);
        fflush(stdin);
        do
        {
            printf("Enter how many students to add to team %s: ", team[i].name);
            scanf("%d", studentsToAdd);
            fflush(stdin);
        }while(studentsToAdd < 0 || studentsToAdd > 8)
        for(j = 0; j < studentsToAdd; j++)
        {
            printf("Enter a name from the database to add to team %s", team[i].name);
            gets(nameToAdd);
            for(k = 0; k < )

        }
    }
    return i;
}
*/
char form()
{
    char r;
    do
    {
        printf("\n---Main menu---\n");
        printf("1- Manage students.\n");
        printf("2- Manage activities.\n");
        printf("3- Manage teams.\n");
        printf("4- Team info.\n");
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
        printf("\n---Team Info---\n");
        printf("1- Right answers.\n");
        printf("2- Average Age.\n");
        printf("3- Time per activity.\n");
        printf("r/R- Return to menu.\n");
        r=getch();
    }
    while (r!='r' && r!='R' && r!='1' && r!='2' && r!='3');
    return r;
}


int init(team_type team[], int *teamQtt)
{
    int i,j,k = 0,m = 0;
    int randomAge,randomID,randomNC,randomTime;
    char teamNames[6][7] = { "team1","team2","team3","team4","team5","team6" };
    char teamLocalities[6][11] = { "local1","local2","local3","local4","local5","local6"};
    char studentNames[64][21] = {  "name1","name2","name3","name4","name5","name6","name7","name8",              //1st team
                                    "name9","name10","name11","name12","name13","name14","name15","name16",      //2nd team
                                    "name17","name18","name19","name20","name21","name22","name23","name24",     //3rd team
                                    "name25","name26","name27","name28","name29","name30","name31","name32",     //4th team
                                    "name33","name34","name35","name36","name37","name38","name39","name40",     //5th team
                                    "name41","name42","name43","name44","name45","name46","name47","name48"     //6th team
                                    /*"name49","name50","name51","name52","name53","name54","name55","name56"     //7th team
                                    "name57","name58","name59","name60","name61","name62","name63","name64"     //8th team*/
                                 };
    int students=6*8;
    (*teamQtt)=6;
    for(i = 0; i < 6; i++)
    {
        strcpy(team[i].name,teamNames[i]);                          //Gives initial values to the structure
        strcpy(team[i].locality,teamLocalities[i]);
        for(j = 0; j < 8; j++, k++)
        {
            strcpy(team[i].student[j].name,studentNames[k]);

            do
            {
                randomAge = rand() % 30;
            }while(randomAge < 10);
            team[i].student[j].age = randomAge;
            if(i%2) team[i].student[j].sex = 'M';
            else team[i].student[j].sex = 'F';
            for(m = 0; m < 5; m++)
            {
                do
                {
                    randomID = rand() % 1000;
                }while(randomID <= 0);
                team[i].student[j].activity[m].id = randomID;
                do
                {
                    randomNC = rand() % 30;
                }while(randomNC <= 0);
                team[i].student[j].activity[m].NC = randomNC;
                do
                {
                    randomTime = rand() % 720;
                    randomTime = randomTime * 10;
                }while(randomTime <= 0);
                team[i].student[j].activity[m].time = randomTime;
            }
        }
    }
    //teamInd
    return students;
}
int averageAge(team_type team[], int teamQtt, int students)
{
    int x=0;
    int i,j;

    for(i=0;i<6;i++)
    {
        for (j=0;j<8;j++)
        {
            x=x+team[i].student[j].age;
        }
    }
    x=x/students;
    return x;
}
int wastedTime (activity_type activity[], int ActNum)
{
    float x=50000;
    int i;
    for (i=0;i<ActNum;i++)
    {
        if (x>activity[i].time)x=activity[i].time;
    }
    return x;
}

void searchStudents (team_type team[], char name[21], int teamQtt)
{
    int x=0,y=0,i,j;
    for (i=0;i<teamQtt;i++)
    {
        for (j=0;j<8;j++)
        {
            if(!(strcmp(team[i].student[j].name, name)))
            {
                x=i;
                y=j;
            }
        }
    }
    if(x!=0)
    {
        printf("--- Student---\n");
        printf("Name: \t%s\n",team[x].student[y].name);
        printf("Age: \t%d\n",team[x].student[y].age);
        printf("Gender: %c\n\n",team[x].student[y].sex);
    }
    else printf("Not found!!!");
}


int fillActivity(activity_type activity[])
{
    int i;
    for(i = 0; i < 10; i++)
    {
        activity[i].id = rand();
    }
    return i;
}

int main()
{
    student_type student[MAX];
    activity_type activity[100];
    team_type teams[100];
    int oldStudentIndex = 0, newStudentIndex = 0, studentsToInsert = 0;
    char studentToDelete[21];
    char teamToInsert[21];
    char studentToSearch[21];
    int oldActivityIndex = 0, newActivityIndex = 0, activitiesToInsert = 0;
    int activityToDelete = 0;
    int oldTeamIndex = 0, newTeamIndex = 0, teamsToInsert = 0;
    char ch;
    int students=0,teamQtt=0, aAge=0, timeWasted=0,ActNum;

    ActNum=fillActivity(activity);

    students=init(teams, &teamQtt);
    oldStudentIndex = teamInd;
    newStudentIndex = oldStudentIndex;
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
                                    printf("Enter the number of students to insert: ");
                                    scanf("%d", &studentsToInsert);
                                    fflush(stdin);
                                    printf("Enter the team's name to insert the students: ");
                                    gets(teamToInsert);
                                    fflush(stdin);
                                    newStudentIndex = oldStudentIndex + studentsToInsert;
                                    oldStudentIndex = insertStudent(teams, oldStudentIndex, newStudentIndex, teamToInsert);
                                    break;
                                }
                            case '2':
                                {
                                    //show student
                                    showStudents(teams, teamQtt);
                                    break;
                                }
                            case '3':
                                {
                                    //delete student
                                    printf("Enter the student's name to delete: ");
                                    gets(studentToDelete);
                                    fflush(stdin);
                                    newStudentIndex = deleteStudent(teams, studentToDelete, newStudentIndex);
                                    break;
                                }
                            case '4':
                                { //search student
                                    printf("Enter the student's name to search: ");
                                    gets(studentToSearch);
                                    fflush(stdin);
                                    searchStudents(student, studentToSearch, teamQtt);

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
                                    oldActivityIndex = insertActivity(teams, oldActivityIndex, newActivityIndex);
                                    break;
                                }
                            case '2':
                                {
                                    //show activity
                                    showActivities(teams, newActivityIndex);
                                    break;
                                }
                            case '3':
                                {
                                    //delete activity
                                    printf("Enter the activity's ID to delete: ");
                                    scanf("%d", &activityToDelete);
                                    newActivityIndex = deleteActivity(teams, activityToDelete, newActivityIndex);
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
                                   /* printf("Enter the number of teams to save: ");
                                    scanf("%d", &teamsToInsert);
                                    newTeamIndex = oldTeamIndex + teamsToInsert;
                                    oldTeamIndex = insertTeam(team, oldTeamIndex, newTeamIndex, student, newStudentIndex);
                                    */break;
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
                                    aAge=averageAge(teams, teamQtt, students);
                                    printf("\nAverage age of the participants: %d\n",aAge);
                                break;
                                }
                            case '3':
                                { //less time wasted per activity
                                    timeWasted=wastedTime(activity, ActNum);
                                    printf("\nTeam with the lowest time: %d\n",timeWasted);
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
