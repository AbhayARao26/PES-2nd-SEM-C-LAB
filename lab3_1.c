/*
    Write a C program to check Vowel or consonant.
    If the user enters a non-alphabetic character,
    it should display error
*/

#include<stdio.h>
int main()
{
    char c;
    int c1;
    printf("Enter a character: \n");
    scanf("%c",&c);
    c1 = c;
    if(c=='A'||c=='a'||c=='E'||c=='e'||c=='I'||c=='i'||c=='O'||c=='o'||c=='U'||c=='u')
    {
        printf("It is a vowel\n");
    }
    else if((c1<=122)&&(c1>=65))
    {
        printf("It is a consonant\n");
    }
    else
        printf("Error, Non-alphabetic character\n");
    return(0);
}
