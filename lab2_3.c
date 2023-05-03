/*
    Declare two variables a,b and a
    pointer variable p such that the
    pointer variable p holds the
    address of a. Increment the value
    in the pointer variable and assign
    it to b. Print the values of a and
    b.
*/

#include<stdio.h>
int main()
{
    int a,b,*p;
    scanf("%d",&a);
    p = &a;
    a=++(*p);
    b=a;
    printf("%d\n%d",a,b);
    return(0);
}
