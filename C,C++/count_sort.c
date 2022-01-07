#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int maximum(int arr[], int n)
{
    int max = INT_MIN;
    for (int i=0; i<n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int * arr, int n)
{
    int max = maximum(arr, n);
    int * count = (int *)malloc((max+1)*sizeof(int *));

    for (int i=0; i<=max; i++)
    {
        count[i] = 0;
    }

    for (int i=0; i<n; i++)
    {
        count[arr[i]]++;
    }

    int i = 0;
    int j = 0;

    while (i <= max)
    {
        if (count[i] > 0)
        {
            arr[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }

    return;
}

int main()
{
    int arr[] = {3, 5, 7, 6, 1, 8, 2, 5};
    int n = sizeof(arr)/sizeof(int);
    
    printArray(arr, n);
    countSort(arr, n);
    printArray(arr, n);
    
    return 0;
}