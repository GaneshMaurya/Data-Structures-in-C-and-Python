#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

    return;
}

int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr)/sizeof(int);

    int j = 0;
    int pivot = 0;

    for (int i=0; i<n; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            j = j+1;
        }
    }

    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}