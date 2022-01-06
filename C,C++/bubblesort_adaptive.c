#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Normal Bubbble Sort
void bubbleSort(int *arr, int n)
{
    int temp;
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    return;
}

// Adaptive Bubble Sort
void bubbleSortAdaptive(int *arr, int n)
{
    int temp;
    int isSorted = 0;
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-1-i; j++)
        {
            isSorted = 1;
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted == 1)
        {
            return;
        }
    }

    return;
}

int main()
{
    int arr[] = {3, 5, 7, 6, 1, 8, 2, 5};
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr)/sizeof(int);

    printArray(arr, n);
    bubbleSort(arr, n);
    // bubbleSortAdaptive(arr, n);
    printArray(arr, n);
    
    return 0;
}