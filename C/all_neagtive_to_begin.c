#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(arr)/sizeof(int);

    int pivot = 0;
    int p = 0;
    
    for (int i=0; i<n; i++)
    {
        if (arr[i] < pivot)
        {
            swap(&arr[p], &arr[i]);
            p++;
        }
    }

    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}