/*
    Length of each word

        Write a C program to read and print the length of each word.
        Implement the below function:
            int countWords(char *text,int *count);
        Note: str contains the input string, count is the array which contains the length of each word. Return back the number of words from the function.
        
        Input Format
            String with or without spaces (String contains maximum of 10 words)

        Output Format
            No. of words in the given string
*/

#include <stdio.h>

int countWords(char *text, int *count)
{
    int num_words = 0;
    int word_length = 0;
    
    while (*text != '\0')
    {
        if (isspace(*text))
        {
            if (word_length > 0)
            {
                count[num_words++] = word_length;
                word_length = 0;
            }
        }
        else
        {
            ++word_length;
        }
        
        ++text;
    }
    
    if (word_length > 0)
    {
        count[num_words++] = word_length;
    }
    
    return num_words;
}

int main()
{
    char text[20];
    int count[100];

    fgets(text, 100, stdin);
    
    int num_words = countWords(text, count);
    
    for (int i = 0; i < num_words; ++i)
    {
        printf("%d ", count[i]);
    }
    printf("\n");
    
    return 0;
}
