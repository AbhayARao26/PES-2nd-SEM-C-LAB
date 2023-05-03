/*
    Write a C program to illustrate control structures as given,
    Take a variable n , print the string "Welcome" initially and then print the numbers from 0 to n and finally print the
    string "Thank you".
*/

#include<stdio.h>
int main()
{
    int i,n;
    scanf("%d",&n);
    printf("Welcome\n");
    for(i=0;i<=n;i++)
        printf("%d\n",i);
    printf("Thank you");
    return(0);
}
