#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student
{
    int roll;
    char name[100];
}STUD;

void init_ptr(STUD s[], STUD *p[], int n)
{
    for(int i=0; i<n; ++i)
        p[i] = &s[i];
}

void swap(STUD **lhs, STUD **rhs)
{
    STUD *temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

void disp(STUD *p[], int n)
{
    for(int i=0; i<n; ++i)
    {
        // printf("%s %d\n", (s+i)->name, (s+i)->roll);
        printf("%d %s\n", p[i]->roll, p[i]->name);
    }
}

void selection_sort_roll_no(STUD *s[], int n)
{
    int i, pos, j;
    for(i=0; i<n; i++)
    {
        printf("in for\n");
        pos = i;
        for(j=i+1; j<n; j++)
        {
            if((s[pos]->roll) > (s[j]->roll))
                pos = j;
        }
        if(pos != i)
            swap(&s[pos], &s[i]);
    }
}

void selection_sort_names(STUD *s[], int n)
{
    int i, pos, j;
    for(i=0; i<n-1; i++)
    {
        pos= i;
        for(j=i+1; j<n; j++)
        {
            if(strcmp(s[pos]->name, s[j]->name) > 0)
                pos= j;
        }
        if(pos != i)
            swap(&s[pos], &s[i]);
    }
}

int main()
{
    FILE *fr = fopen("/Users/abhayarao/Documents/PES Engineering/1st YEAR/2nd SEM/C PROGRAMMING/C LAB PROGRAMS/LAB - 11/student.csv", "r");
    char a[200];
    fgets(a, 200, fr);
    // printf("%s", a);
    char *item;
    STUD s[100];
    int i = 0;
    while(fgets(a, 200, fr))
    {
        item = strtok(a, ",");
        s[i].roll = atoi(item);
        item = strtok(NULL, ",");
        strcpy(s[i].name, item);
        i++;
    }
    int n = i;
    fclose(fr);
    STUD *p[100];
    init_ptr(s, p, n);
    disp(p, n);
    int ch;
    printf("Enter the choice:\n1. Sort on roll\n2. Sort on name\n0. Exit\n\n");
    scanf("%d",&ch);
    switch (ch)
    {
        case 1:
            selection_sort_roll_no(p, n);
            disp(p, n);
            break;
        case 2:
            selection_sort_names(p, n);
            disp(p, n);
            break;
        default:
            printf("Exiting the program");
            exit(0);
    }
    FILE *fw = fopen("/Users/abhayarao/Documents/PES Engineering/1st YEAR/2nd SEM/C PROGRAMMING/C LAB PROGRAMS/LAB - 11/student_sorted.csv", "w");
    fprintf(fw, "Roll Number, Name\n");
    i = 0;
    while(i<n)
    {
        fprintf(fw, "%d, %s", p[i]->roll, p[i]->name);
        i++;
    }
    fclose(fw);
    printf("Sorted data is written to a file student_sorted.csv\n");
    return 0;
}

