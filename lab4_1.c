/*
 C program on Functions:
    Write a C function to check whether a given number is prime and use
    that to find the next prime number, greater than a given number.

    Implement the below functions:
    bool isPrime(int n):
    Returns true or false depending on if a number is prime or not

    int nextPrime(int n);
    Returns the next prime number after n
    Input Format
        X: A positive integer
    Output Format
        Y: First Prime number after X
 Example:
 input - 4
 output - 5
*/

#include<stdio.h>
#include<stdbool.h>
bool isPrime(int n)
{
    int count = 0;
    int iterator = 1;
    bool mark = false;
    while(iterator<=(n/2))
    {
        if(n%iterator==0)
        {
            count += 1;
        }
        if(count==1)
        {
            mark = true;
        }
        else
        {
            mark = false;
        }
        iterator++;
    }
    return mark;
}
int nextPrime(int n)
{
    int returner = 0;
    while(returner==0)
    {
        n++;
        returner=isPrime(n);
    }
    return n;
}
int main(void)
{
    int value;
    scanf("%d",&value);
    int nextPrimeVal = nextPrime(value);
    printf("%d",nextPrimeVal);
}
