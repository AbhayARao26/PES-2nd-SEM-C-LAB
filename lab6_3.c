/*
    Vowels and Consonants

        Write a C program to find frequency of each of the vowels and total count of consonants.
        Implement the below function:
            void vowFreqConCount(char *str,int *count);
        Note: str contains the input string, count is the array which contains frequency of the vowels a, e, i, o, u in index location 0, 1, 2, 3, 4 respectively and total count of consonants in index location 5.
    
    Input Format
        S: Input string
    
    Output Format
        I': integers representing the frequency of the vowels a,e,i,o,u and total count of consonants with spaces in the given order
*/

#include <stdio.h>
#include <string.h>

void vowFreqConCount(char *str, int *count)
{
    int len = strlen(str);
    int i;
    for (i = 0; i <= 5; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < len; i++)
    {
        switch (str[i])
        {
            case 'a':
            case 'A':
                count[0]++;
                break;
            case 'e':
            case 'E':
                count[1]++;
                break;
            case 'i':
            case 'I':
                count[2]++;
                break;
            case 'o':
            case 'O':
                count[3]++;
                break;
            case 'u':
            case 'U':
                count[4]++;
                break;
            default:
                if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')
                {
                    count[5]++;
                }
                break;
        }
    }
}

int main() {
    char str[100];
    int count[6] = {0};
    fgets(str, 100, stdin);
    vowFreqConCount(str, count);
    printf("%d %d %d %d %d %d\n", count[0], count[1], count[2], count[3], count[4], count[5]);
    return 0;
}
