#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid+1;
    int k = low;
    int B[high+1];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            B[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            B[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        B[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = arr[j];
        k++;
        j++;
    }
    for (int i=low; i<=high; i++)
    {
        arr[i] = B[i];
    }
    return;
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high-low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
    return;
}

int main()
{
    int arr[] = {3, 5, 7, 6, 1, 8, 2, 5};
    int n = sizeof(arr)/sizeof(int);
    
    printArray(arr, n);
    mergeSort(arr, 0, n-1);
    printArray(arr, n);
    
    return 0;
}