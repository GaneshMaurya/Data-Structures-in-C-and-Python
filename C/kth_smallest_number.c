#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int pi = s;

    for (int i=s; i<e-1; i++)
    {
        if (arr[i] >= pivot)
        {
            swap(&arr[i], &arr[pi]);
            pi++;
        }
    }
    swap(&arr[pi], &arr[e]);
    return (pi+1);
}

void quicksort(int arr[], int s, int e)
{
    if (s>=e)
    {
        return;
    }
    int pi = partition(arr, s, e);
    quicksort(arr, s, pi-1);
    quicksort(arr, pi+1, e);
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int k = 3;
    int n = sizeof(arr)/sizeof(int);

    quicksort(arr, 0, n-1);

    printf("%d", arr[k-1]);
    
    return 0;
}