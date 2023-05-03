/*
 C program on Functions
    Write a C function to check if a given number is a perfect number or not.

    Note:
    Perfect number is a positive integer that is equal to the sum of its proper divisors. Eg: 6, which is the sum of 1,2 and 3.

    Implement the below functions:
    int checkPerfect(int n);
    Returns 1 if ‘n’ is a perfect number, otherwise returns 0.
    Input Format
        n
        where n is a positive integer
    Output Format
        Message: “Perfect number” if the number is a perfect number
        Message: “Not a perfect number” if the the number is not a perfect number
 Example:
 input - 6
 output - Perfect Number
*/

#include<stdio.h>
int checkPerfect(int n)
{
    int s=0;
    for(int i=1; i<n; i++)
    {
        if(n%i==0)
        {
            s+=i;
        }
    }
    if(s==n)
    return 1;
    else
    return 0;
}
int main()
{
    int n,b;
    scanf("%d",&n);
    b= checkPerfect(n);
    if(b==1)
    printf("Perfect number");
    else
    printf("Not a perfect number");
    return 0;
}
