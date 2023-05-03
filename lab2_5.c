/*
    Write a C program to accept a
    coordinate point in an x-y
    coordinate system and determine in
    which quadrant the coordinate point
    lies.
*/

#include<stdio.h>
int main()
{
    int x,y;
    scanf("%d\n%d",&x,&y);
    if((x>0)&&(y>0))
    {
        printf("First Quadrant");
    }
    else if((x>0)&&(y<0))
    {
        printf("Fourth Quadrant");
    }
    else if((x<0)&&(y<0))
    {
        printf("Third Quadrant");
    }
    else if((x<0)&&(y>0))
    {
        printf("Second Quadrant");
    }
    return(0);
}
