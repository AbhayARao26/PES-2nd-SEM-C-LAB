/*
    Array of Structures

    Define a structure in C called cricket that will describe the following information:
        player name
        team name (country name)
        batting average

    Using cricket, write a program to read the information about all the N players, and print a team-wise sorted list (ascending order) also containing the names of players with their batting average.
 
    Write functions for the following:
        i) Read the information of all the N players: void readInfo(CRICKET a[],int n);
        ii) Sorting the players: void sort(CRICKET a[],int n);
        iii) Displaying a team-wise list containing names of player with their batting average: void display(CRICKET a[],int n);
 
    Input Format
        N-No of Players
        P N TN BA - Player Name, Team Name, batting Average
 
    Output Format
        After Team-wise Sorting, the Player list is :
        PN TN BA
        so on....
*/

#include <stdio.h>
#include <string.h>

typedef struct Cricket
{
    char p_name[20];
    char t_name[20];
    int bat_avg;
}CRICKET;

void readInfo(CRICKET a[], int n)
{
    for (int i=0; i<n; i++)
    {
        scanf("%s %s %d", a[i].p_name, a[i].t_name, &a[i].bat_avg);
    }
}

void sort(CRICKET a[], int n)
{
    for (int i=0; i<n-1; i++)
    {
        for( int j=0; j<n-i-1; j++)
        {
            if (strcmp(a[j].t_name,a[j+1].t_name) > 0)
            {
                CRICKET temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void display(CRICKET a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s %s %d\n", a[i].p_name, a[i].t_name, a[i].bat_avg);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    CRICKET players[n];
    readInfo(players, n);
    sort(players, n);
    display(players, n);
    return 0;
}
