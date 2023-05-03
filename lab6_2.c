/*
    Substring

        Write a C function strend (s , t ), which returns
        1 if the string t occurs at the end of the string
        s, and zero otherwise
 
    Input Format
        S1:
            Input String1
        S2:
            Input string 2
    
    Output Format
        0 or 1 based on the input
*/

#include <stdio.h>
#include <string.h>

int strend(char s[], char t[])
{
    int len1 = strlen(s);
    int len2 = strlen(t);

    if (len2 > len1)
    {
        return 0;
    }

    int i = len1 - len2;
    int j = 0;

    while (s[i] != '\0' && t[j] != '\0')
    {
        if (s[i] != t[j])
        {
            return 0;
        }
        i++;
        j++;
    }

    if (s[i] == '\0' && t[j] == '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char s1[100], s2[100];
    scanf("%s", s1);
    scanf("%s", s2);
    printf("%d",strend(s1,s2));
    return 0;
}

