/*
    Frequency of words

        Write a C function to count the number of occurrences of a given character.
        Use this to find the number of occurrences of every character in a word.
    
    Input Format
        S: Input String
    Output Format
        S: characters with their frequencies
*/

#include <stdio.h>
#include <string.h>

void countChars(char str[])
{
    int len = strlen(str);
    int freq[26] = {0};
    
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            freq[str[i] - 'a']++;
        }
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            printf("%c %d\n", 'a' + i, freq[i]);
        }
    }
}

int main()
{
    char str[10];
    scanf("%s",str);
    countChars(str);
    return 0;
}

