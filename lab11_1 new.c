#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student
{
    int roll;
    char name[200] ;
}STUD;

int sorterInsertion(STUD*, int);

int main()
{
    printf("Enter number of CSV Records ");
    int numChar;
    scanf("%d", &numChar);
    
    FILE* fp=fopen("/Users/abhayarao/Documents/PES Engineering/1st YEAR/2nd SEM/C PROGRAMMING/C LAB PROGRAMS/LAB - 11/student.csv", "r");
    STUD unSArray[numChar];
    char string[50];
    
    
    int i=0;
    while (fgets(string, 50, fp)) {
        char* temp=strtok(string, ",");
        unSArray[i].roll=atoi(temp);
        char* tempNew=strtok(NULL, ",");
        strcpy(unSArray[i].name, tempNew);
        printf("%d %s", unSArray[i].roll, unSArray[i].name);
        i++;
        
    }
    int selector=0;
    printf("Enter your Choice\n Choose 1 if you want to sort by Roll\n Choose 2 if you want to sort by Name\n");
    scanf("%d", &selector);
    switch (selector)
    {
        case 1:
        {
            
            for (int i=1; i<(sizeof(unSArray)/sizeof(STUD)); i++)
            {
                int j=i-1;
                STUD key=unSArray[i];
                while (j>0 && unSArray[j].roll>key.roll)
                {
                    unSArray[j+1]=unSArray[j];
                    j-=1;
                }
                unSArray[j+1]=key;
                
            }
            for (int i=0; i<(int)(sizeof(unSArray)/sizeof(STUD)); i++)
            {
                printf("Sorted Roll Call, given by %dth is      %d      %s\n", i, unSArray[i].roll, unSArray[i].name);
            }
            break;
        }
        case 2:
            {
                sorterInsertion(unSArray, (int)(sizeof(unSArray))/sizeof(STUD));
                for (int i=0; i<(int)(sizeof(unSArray)/sizeof(STUD)); i++)
                {
                    printf("Sorted Postion Name, given by %dth is     %d     %s\n", i, unSArray[i].roll, unSArray[i].name);
                }
                break;
            }
        default:
            break;
        }
        
    }

int sorterInsertion(STUD s[], int n)
{
    for (int i=1; i<n; i++) {
        STUD key=s[i];
        int j=i-1;
        while (j>=0 && (strcmp(s[j].name, s[i].name)>0)) {
            s[j+1]=s[j];
            j--;
            
        }
        s[j+1]=key;
        
    }
    return 0;
}



