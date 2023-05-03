/*
    Structures and Functions

    Write a C Program to Add  two Complex Numbers by Passing Structure to a Function.
 
    Implement the below functions:
        void readComplex(COMPLEX *a);
        void addComplex(COMPLEX *a,COMPLEX *b,COMPLEX *c);
        void displayComplex(COMPLEX *a);
 
    Input Format
        R  I : real & imaginary part of Complex no 1 separted by space
        R'  I' : real & imaginary part of Complex no 2 separted by space
 
    Output Format
        Sum of Complex nos in the form: Real part + Imaginary part succeded by character i
*/

#include <stdio.h>

typedef struct Complex
{
    float r;
    float i;
}COMPLEX;

void readComplex(COMPLEX *a)
{
    scanf("%f %f", &(*a).r, &(*a).i);
}

void addComplex(COMPLEX *a, COMPLEX *b, COMPLEX *c)
{
    (*c).r = (*a).r + (*b).r;
    (*c).i = (*a).i + (*b).i;
}

void displayComplex(COMPLEX *a)
{
    printf("%.1f + %.1fi", (*a).r, (*a).i);
}

int main()
{
    COMPLEX a, b, c;
    readComplex(&a);
    readComplex(&b);
    addComplex(&a, &b, &c);
    displayComplex(&c);
    return 0;
}
