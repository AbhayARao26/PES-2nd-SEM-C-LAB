/*
 C program on Recursion
    Create a recursive function to generate hailstone sequence up to 1.

    Implement the below functions:
    int getNextValue(int n);
    Returns the next value in the sequence

    int getHailstone(int n);
    Recursively prints the values in the sequence

    Note :
    The Hailstone sequence of numbers can be generated from a starting positive integer, n by: If n is 1 then the sequence
    ends. If n is even then the next n of the sequence = n/2. If n is odd then the next n of the sequence = (3 * n) + 1.
 
    Input Format
        n
        where n is a positive integer
    Output Format
        Sequence of numbers separated by space
 Example:
 input - 3
 output - 3 10 5 16 8 4 2 1
*/

#include<stdio.h>
int getNextValue(int n)
{
    int i = n;
    if(i%2==0)
    {
        i/=2;
    }
    else
    {
        i = (3*i)+1;
    }
    return(i);
}
int getHailStone(int n)
{
    int hlSe = n;
    if(hlSe==1)
    {
        printf("%d ",hlSe);
    }
    else
    {
        printf("%d ",hlSe);
        getHailStone(getNextValue(hlSe));
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    getHailStone(n);
}
