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
    int arr[] = {1, 2, 0, 1, 0, 0, 2, 1, 0, 2, 2, 1};
    int n = sizeof(arr)/sizeof(int);

    int low = 0;
    int mid = 0;
    int high = n-1;

    while (mid < high)
    {
        switch(arr[mid])
        {
            case 0:
                swap(&arr[low], &arr[mid]);
                mid++;
                low++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(&arr[mid], &arr[high]);
                high--;
                break;
        }
    } 

    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}