/*
    Program to find the value of d where
    d = (p+q)*n
*/
#include<stdio.h>
int main()
{
    int p,q,n,d;
    scanf("%d\n%d\n%d",&p,&q,&n);
    p = p++;
    q = ++q;
    d = (p+q)*n;
    printf("%d",d);
    return(0);
}
