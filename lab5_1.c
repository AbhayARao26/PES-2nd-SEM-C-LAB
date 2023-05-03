/*
 Reverse the Array

 Write C functions to reverse the array elements
 a) using index notation
 b) using pointer notation

 Note: The elements in the array have to be reversed. Do not just display the array elements in reverse order. You are expected to solve the problem using both array index notation and pointer notation.
 You may write a copyArray() function to store the input array in another array, so that the original input values can be used for reversing the array the second time.

 Implement the below functions:
    void readArray(int a[],int n);
    void displayArray(int a[],int n);
    void copyArray(int a[],int ori[],int n);
    void reverseArray1(int a[],int n);
    void reverseArray2(int *a,int n);
 
 Input Format
    First line: n representing number of elements in the array, 0 < n ≤ 10
    Second line: n numbers separated by space
 Output Format
    First line Message: "Using index notation"
    Second line: Input array separated by space
    Third line: Reversed array separated by space
    Fourth line Message: "Using pointer notation"
    Fifth line: Input array separated by space
    Sixth line: Reversed array separated by space
*/

#include<stdio.h>
int main()
{
    // Using index notation
    int n, arr[100], i=0;
    int *p;
    scanf("%d",&n);
    while(i<n)
    {
        scanf("%d ",&arr[i]);
        i++;
    }
    printf("Using index notation\n");
    i=0;
    while(i<n)
    {
        printf("%d ",arr[i]);
        i++;
    }
    printf("\n");
    i = n-1;
    while(i>=0)
    {
        printf("%d ",arr[i]);
        i--;
    }
    printf("\nUsing pointer notation\n");
    i=0;
    while(i<n)
    {
        printf("%d ",arr[i]);
        i++;
    }
    printf("\n");
    for(p=&arr[n-1]; p>=&arr[0]; p--)
    {
        printf("%d ", *p);
    }
    return(0);
}
