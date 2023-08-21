#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *fp1 =fopen("/Users/abhayarao/Documents/PES Engineering/1st YEAR/2nd SEM/C PROGRAMMING/C LAB PROGRAMS/LAB - 10/FileOne.txt", "r");
    FILE *fp2 =fopen("/Users/abhayarao/Documents/PES Engineering/1st YEAR/2nd SEM/C PROGRAMMING/C LAB PROGRAMS/LAB - 10/FileTwo.txt", "r");
    int column, position, line;
    line=1;
    position=0;
    int errorCount=0;
    char c1=getc(fp1);
    char c2=getc(fp2);
    while (c2!=EOF && c2!=EOF)
    {
        position++;
        if (c1=='\n' || c2=='\n')
        {
            line++;
            position=0;
        }
        if (c1!=c2)
        {
            errorCount++;
            printf("Error Number: %d\nLine Number: %d\nColumn Number: %d\n",errorCount, line, position);

        }
        c1=getc(fp1);
        c2=getc(fp2);
        if (c1==EOF || c2==EOF)
        {
            break;
        }
    }
}

