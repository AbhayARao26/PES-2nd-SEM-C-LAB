#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *fp1 = fopen("/Users/abhayarao/Documents/PES Engineering/1st YEAR/2nd SEM/C PROGRAMMING/C LAB PROGRAMS/LAB - 10/file.txt", "w");
    int noLine;
    char l[100];
    printf("Enter number of lines\n");
    scanf("%d", &noLine);
    getchar();
    printf("Enter the %d lines\n", noLine);
    int i;
    for (i=0; i<noLine; i++)
    {
        fgets(l, sizeof(l), stdin);
        fputs(l, fp1);
    }
    fclose(fp1);
}
