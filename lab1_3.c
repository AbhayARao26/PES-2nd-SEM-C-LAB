/*
    Program to take 2 inputs, 1 integer
    and 1 character, and printing their sum
    as a floating point value
*/
#include<stdio.h>
int main()
{
    int n;
    char c;
    scanf("%d\n",&n);
    scanf("%c",&c);
    float f = n + c;
    printf("%f",f);
    return(0);
}
