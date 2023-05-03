/*
    Program to take 3 integers as input x,y,z
    and evaluate the expression
    a = x&&y||z++
    and print the value of z
*/
#include<stdio.h>
int main()
{
    int a,x,y,z;
    scanf("%d\n%d\n%d\n",&x,&y,&z);
    a = x&&y||z++;
    printf("%d",z);
    return(0);
}
