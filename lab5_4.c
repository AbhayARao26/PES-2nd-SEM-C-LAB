/*
 Delete an array element

 Write a C function to delete an array element at a specified position. A valid position for deletion: 0≤pos<n, where n is the no. of elements in the array.
 Your code should check for position validity. In case the position is invalid, display the message "Invalid position".

 Eg:    Consider an array a = {10, 5, 3, 2}
        After deleting an element at pos 0: array a = {5, 3, 2}

        Consider an array a = {10, 5, 3, 2}
        Trying to delete an element at position -1 (or lesser) or position 4 (or greater) should give the message: "Invalid position".

 Implement the below functions:
    void readArray(int arr[],int n);
    void displayArray(int arr[],int n);
    int checkPosValidity(int n,int pos);    //return 0 for invalid position, else 1
    void delEleAtPos(int arr[],int *n,int pos);    //Pass the number of elements in array by address. After deleting an element reduce the number of elements by 1.

 Input Format
    First line: n representing number of elements in the array, 0<n≤ 10
    Second line: n numbers separated by space
    Third line: Position of the element to be deleted
 
 Output Format
    In case of valid position:
    First line: input array elements separated by space
    Second line: elements after deleting an element at the specified position

    In case of invalid position:
    Message: "Invalid position"
*/

#include <stdio.h>

void readArray(int arr[], int n);
void displayArray(int arr[], int n);
int checkPosValidity(int n, int pos);
void delEleAtPos(int arr[], int *n, int pos);

int main()
{
    int arr[10], n, pos;
    scanf("%d", &n);
    readArray(arr, n);
    scanf("%d", &pos);
    if (checkPosValidity(n, pos))
    {
        displayArray(arr, n);
        delEleAtPos(arr, &n, pos);
        displayArray(arr, n);
    }
    else
    {
        printf("Invalid position\n");
    }
    return 0;
}

void readArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int checkPosValidity(int n, int pos)
{
    if (pos < 0 || pos >= n)
    {
        return 0;
    }
    return 1;
}

void delEleAtPos(int arr[], int *n, int pos)
{
    for (int i = pos+1; i < (*n)-1; i++)
    {
        arr[i] = arr[i+1];
    }
        (*n)--;
}
