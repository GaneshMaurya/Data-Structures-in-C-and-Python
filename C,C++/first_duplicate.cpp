#include <bits/stdc++.h>
using namespace std;

int firstDuplicate(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        if (arr[abs(arr[i])] < 0)
        {
            return abs(arr[i]);
        }
        else
        {
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        }
    }

    return -1;
}

int main()
{
    int arr[] = {2, 1, 3, 5, 3, 2};
    int n = sizeof(arr)/sizeof(int);
    
    cout<<firstDuplicate(arr, n);

    return 0;
}