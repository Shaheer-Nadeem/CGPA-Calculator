#include <stdio.h>
#include <math.h>
#include <string.h>
void DegreeStatus(int sem_no, float cgpa, int *curr_status);
void main()
{
    int a,b,c,d,i,j,sem,subs[6], deg_status=0, *p=&deg_status;
    char grade[4]; float GPA[8][7],sem_GPA[7],gpa_count[6]={0},sem_GPA_count=0,CGPA;
    printf("\n\t\tWelcome to CGPA Assistant!\n");
    do{
    printf("\nHow many semesters have you completed? (Max=8):  ");
    scanf("%d", &sem);}
    while(sem>8||sem<=0);
    int std_marks[8][7];
    for(i=0;i<8;i++)
    {
        for(j=0;j<7;j++)
            std_marks[i][j]=-1;
    }
    for(i=0;i<sem;i++)
    {
        do{
        printf("\n\t**Semester %d**\n", i+1);
        printf("\nHow many subjects are you studying in this semester?(Max=7):  ");
        scanf("%d", &subs[i]);}
        while (subs[i]<=0||subs[i]>7);
        for(j=0;j<subs[i];j++)
        {
            do{
            printf("Enter subject %d marks:  ",j+1);
            scanf("%d", &std_marks[i][j]);}
            while(std_marks[i][j]<0||std_marks[i][j]>100);
        }

    }
    for(i=0;i<sem;i++)
    {
        printf("\n=======================");
        printf("\nSemester %d Result", i+1);
        printf("\n=======================");
        printf("\nSubject\t\tGrade\tGPA\tMarks");
        for(j=0;j<subs[i];j++)
        {
            if(std_marks[i][j]>=90&&std_marks[i][j]<=100)
            {
                strcpy(grade, "A"); GPA[i][j]=4.0;gpa_count[i]+=GPA[i][j];
            }
            else if(std_marks[i][j]>=85&&std_marks[i][j]<=89)
            {
                strcpy(grade, "A-"); GPA[i][j]=3.7;gpa_count[i]+=GPA[i][j];
            }
            else if(std_marks[i][j]>=80&&std_marks[i][j]<=84)
            {
                strcpy(grade, "B+"); GPA[i][j]=3.3;gpa_count[i]+=GPA[i][j];
            }
            else if(std_marks[i][j]>=75&&std_marks[i][j]<=79)
            {
                strcpy(grade, "B"); GPA[i][j]=3.0;gpa_count[i]+=GPA[i][j];
            }
            else if(std_marks[i][j]>=70&&std_marks[i][j]<=74)
            {
                strcpy(grade, "B-"); GPA[i][j]=2.7;gpa_count[i]+=GPA[i][j];
            }
            else if(std_marks[i][j]>=65&&std_marks[i][j]<=69)
            {
                strcpy(grade, "C+"); GPA[i][j]=2.3;gpa_count[i]+=GPA[i][j];
            }
            else if(std_marks[i][j]>=60&&std_marks[i][j]<=64)
            {
                strcpy(grade, "C"); GPA[i][j]=2.0;gpa_count[i]+=GPA[i][j];
            }
            else if(std_marks[i][j]>=55&&std_marks[i][j]<=59)
            {
                strcpy(grade, "C-"); GPA[i][j]=1.7;gpa_count[i]+=GPA[i][j];
            }
            else if(std_marks[i][j]>=50&&std_marks[i][j]<=54)
            {
                strcpy(grade, "D"); GPA[i][j]=1.3;gpa_count[i]+=GPA[i][j];
            }
            else {strcpy(grade, "F"); GPA[i][j]=0;gpa_count[i]+=GPA[i][j];}
            printf("\n%d\t\t%s\t%.2f\t%d", j+1,grade,GPA[i][j],std_marks[i][j]);
            printf("\n");
        }
        sem_GPA[i]=(gpa_count[i])/(float)j; sem_GPA_count+=sem_GPA[i];
        CGPA=(sem_GPA_count)/(float)(i+1);
        printf("\n\t\tSemester GPA: %.2f", sem_GPA[i]);
        printf("\n\t\tTotal  CGPA:  %.2f", CGPA);
        DegreeStatus(i+1, CGPA, p);
        if (deg_status==0)
            printf("\n\t\tDegree Status: Continued");
        else if(deg_status==1)
            printf("\n\t\tDegree Status: Probation");
        else if(deg_status==2)
            {printf("\n\t\tDegree Status: DI");
            printf("\n\tStart Over from 1st Semester. Better Luck Next Time!");
            break;}
        else if(deg_status==3)
            printf("\n\t\tDegree Status: Completed");
    }
    printf("\n\n\n");
    system("pause");
}
void DegreeStatus(int sem_no, float cgpa, int *curr_status)
{
    if (cgpa>=2&&sem_no==8)
        *curr_status=3;
    else if(cgpa<2)
        *curr_status=1;
    else if (*curr_status==1&&cgpa<2)
        *curr_status=2;
    else if(*curr_status==1&&cgpa>=2)
        *curr_status=0;

}
