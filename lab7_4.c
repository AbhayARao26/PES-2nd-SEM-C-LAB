/*
    Matrix multiplication

    Write a C program to multiply two matrices.
 
    Implement the below functions:
        void readMatrix(int m,int n,int a[][n]);
        void displayMatrix(int m,int n,int a[][n]);
        void multiplyMatrix(int m,int n,int p,int q,int a[m][n],int b[p][q],int c[m][q]);
 
    Input Format
        First line: m n --> order of matrix 1 separated by space
        Second line: p q --> order of matrix 2 separated by space
        Third line: m*n integers of matrix 1 separated by space
        Fourth line: p*q integers of matrix 2 separated by space
 
    Output Format
        If n != p, message: Matrix multiplication is not possible
        If n == p, matrix of order m x q in matrix format
*/

#include<stdio.h>

void readMatrix(int m, int n, int a[][n])
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void displayMatrix(int m, int n, int a[][n])
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int m, int n, int p, int q, int a[m][n], int b[p][q], int c[m][q])
{
    if(n!=p)
    {
        printf("Matrix multiplication is not possible");
        return;
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<q;j++)
        {
            c[i][j]=0;
            for(int k=0;k<n;k++)
            {
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    displayMatrix(m,q,c);
}

int main()
{
    int m,n,p,q;
    scanf("%d %d",&m,&n);
    scanf("%d %d",&p,&q);
    int a[m][n];
    readMatrix(m,n,a);
    int b[p][q];
    readMatrix(p,q,b);
    int c[m][q];
    multiplyMatrix(m,n,p,q,a,b,c);
    return 0;
}
