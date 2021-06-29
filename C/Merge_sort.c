#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;

    int nl = m - l + 1;
    int nr = r - m;

    int left[nl], right[nr];

    for (i=0; i<nl; i++)
    {
        left[i] = arr[l+i];
    }

    for (j=0; j<nr; j++)
    {
        right[j] = arr[m+1+j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i<nl && j<nr)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < nl)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < nr)
    {
        arr[k] = right[j];
        j++;
        k++;
    } 
}

void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r-l)/2;

        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {6, 5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(int);

    mergesort(arr, 0, n-1);

    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
}