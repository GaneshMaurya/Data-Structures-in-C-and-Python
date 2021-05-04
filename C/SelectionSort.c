#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SelectionSort(int A[], int n)
{
    int i, j, iMin;
    for (i=0; i<n-1; i++)
    {
        iMin = i;
        for (j=i+1; j<n; j++)
        {
            if (A[j] < A[iMin])
            {
                iMin = j;
            }
            swap(&A[i], &A[iMin]);
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

    SelectionSort(A, n);
    printArray(A, n);

    return 0;
}