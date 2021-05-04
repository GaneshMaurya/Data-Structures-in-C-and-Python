#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int A[], int n)
{
    int i, j;
    for (i=0; i<n-1; i++)
    {
        for (j=i+1; j<n; j++)
        {
            if (A[j] < A[i])
            {
                swap(&A[i], &A[j]);
            }   
        }
    }
}

void printArray(int A[], int n)
{
    for (int i=0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int A[] = {7, 5, 4, 8, 1, 2, 9};
    int n = sizeof(A)/sizeof(A[0]);

    BubbleSort(A, n);
    printArray(A, n);

    return 0;
}