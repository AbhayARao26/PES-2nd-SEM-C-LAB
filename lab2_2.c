/*
    Write a C program to illustrate the
    control structures as given ,
    Declare a variable i , until i is
    less than 10 , print the string
    "hello" ,further if until i is less
    than 8 , then print the string "bye"
*/

#include<stdio.h>
int main()
{
    int i=0;
    scanf("%d",&i);
    while(i<10)
    {
        printf("hello\n");
        while(i<7)
        {
            printf("bye\n");
            i++;
        }
        i++;
    }
    return(0);
}
