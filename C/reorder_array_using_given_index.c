/*Given two integer arrays of same size, “arr[]” and “index[]”, 
reorder elements in “arr[]” according to given index array. 
It is not allowed to given array arr’s length.*/

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int index[], int s, int e)
{
    int pivot = index[e];
    int pi = s;
    
    for (int i=s; i<e-1; i++)
    {
        if (index[i] <= pivot)
        {
            swap(&index[i], &index[pi]);
            swap(&arr[i], &arr[pi]);
            pi++;
        }
    }
    swap(&index[pi], &index[e]);
    swap(&arr[pi], &arr[e]);
    return pi+1;
}

void arrange(int arr[], int index[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int pi = partition(arr, index, s, e);
    arrange(arr, index, s, pi-1);
    arrange(arr, index, pi+1, e);
}

int main()
{
    int arr[] = {50, 40, 70, 60, 90};
    int index[] = {3,  0,  4,  1,  2};
    int n = sizeof(arr)/sizeof(int);

    arrange(arr, index, 0, n-1);

    for (int i=0; i<n; i++)
    {
        printf("%d ", index[i]);
    }

    return 0;
}