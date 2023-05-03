/*
    Structures

    Write a Program in C to add two distances in the inch-feet system using structures.
 
    Implement the below functions:
        void readDistance(DISTANCE *d);
        DISTANCE addDistance(DISTANCE *d1, DISTANCE *d2);
    void displayDistance(DISTANCE *d);
 
    Input Format
        Feet :  int
        Inch : float
        Feet' : int
        Inch' : float
 
    Output Format
        Sum of Distances in the form: Feet'-Inch
*/

#include<stdio.h>
typedef struct distance
{
    int feet;
    float inch;
}DISTANCE;

void readDistance(DISTANCE *d)
{
    scanf("%d",&(*d).feet);
    scanf("%f",&(*d).inch);
}

DISTANCE addDistance(DISTANCE *d1, DISTANCE *d2)
{
    DISTANCE result;
    result.feet = (*d1).feet + (*d2).feet;
    result.inch = (*d1).inch + (*d2).inch;
    if(result.inch>=12)
    {
        result.feet = result.feet + (int)result.inch/12;
        result.inch = result.inch - ((int)result.inch / 12) * 12;
    }
    return result;
}

void displayDistance(DISTANCE *d)
{
    printf("%d\'-%.1f", (*d).feet, (*d).inch);
}

int main()
{
    DISTANCE d1, d2, result;
    readDistance(&d1);
    readDistance(&d2);
    result = addDistance(&d1, &d2);

    displayDistance(&result);
    return 0;
}
