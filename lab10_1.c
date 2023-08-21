#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *fp1 =fopen("/Users/abhayarao/Documents/PES Engineering/1st YEAR/2nd SEM/C PROGRAMMING/C LAB PROGRAMS/LAB - 10/file1.txt","r");
    FILE *fp2 =fopen("/Users/abhayarao/Documents/PES Engineering/1st YEAR/2nd SEM/C PROGRAMMING/C LAB PROGRAMS/LAB - 10/file2.txt","r");
    char l[100];
    FILE *fp3 =fopen("/Users/abhayarao/Documents/PES Engineering/1st YEAR/2nd SEM/C PROGRAMMING/C LAB PROGRAMS/LAB - 10/file3.txt","w");
    if (fp3==NULL)
        printf("Unable to create the file\n");
    else
    {
        printf("File created Successfully, merging now\n");
        while(fgets(l, sizeof(l), fp1) != NULL)
        {
            fputs(l, fp3);
        }
        while(fgets(l, sizeof(l), fp2) != NULL)
        {
            fputs(l, fp3);
        }
    }
    printf("Files Merged!\n");
    return 0;
}

