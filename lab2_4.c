/*
    Evaluate y = a | b where a = x & y and b =  y=4.
*/

#include<stdio.h>
int main()
{
    int a,b,x,y;
    scanf("%d\n%d",&x,&y);
    a = x&y;
    b = 4;
    y = a|b;
    printf("%d",y);
    return(0);
}
