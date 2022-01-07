#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int *arr, int n)
{
    int indexOfMin, temp;
    for (int i=0; i<n-1; i++)
    {
        indexOfMin = i;
        for (int j=i+1; j<n; j++)
        {
            if (arr[j] < arr[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp;
    }
    return;
}

int main()
{
    int arr[] = {3, 5, 7, 6, 1, 8, 2, 5};
    int n = sizeof(arr)/sizeof(int);
    
    printArray(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}