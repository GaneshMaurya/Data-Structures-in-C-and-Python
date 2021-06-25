#include <stdio.h>
#include <stdbool.h>

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
        if (arr[i] <= pivot)
        {
            swap(&arr[i], &arr[pi]);
            pi++;
        }
    }
    swap(&arr[pi], &arr[e]);
    return pi+1;
}

void quicksort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int pi = partition(arr, s, e);
    quicksort(arr, s, pi-1);
    quicksort(arr, pi+1, e);
}

int main()
{
    int arr[] = {11, 15, 6, 8, 9, 10};
    int sum = 16;
    int n = sizeof(arr)/sizeof(int);

    quicksort(arr, 0, n-1);

    int l = 0;
    int r = n-1;
    bool res = false;

    for (int i=0; i<n; i++)
    {
        if (arr[l] + arr[r] == sum)
        {
            res = true;
            break;
        }
        else if (arr[l] + arr[r] > sum)
        {
            r--;
        }
        else
        {
            l++;
        }
    }

    printf(res ? "true" : "false");
    
    return 0;
}