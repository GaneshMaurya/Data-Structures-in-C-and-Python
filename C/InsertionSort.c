#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void InsertionSort(int A[], int n)
{
    int value, hole;
    for (int i=0; i<n-1; i++)
    {
        value = A[i];
        hole = i;

        while (hole > 0 && A[hole-1] > value)
        {
            A[hole] = A[hole-1];
            hole = hole-1;
        }
        A[hole] = value;
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

    InsertionSort(A, n);
    printArray(A, n);

    return 0;
}