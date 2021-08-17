/*
Given heights of n towers and a value k. 
We need to either increase or decrease the height of every tower by k (only once) where k > 0. 
The task is to minimize the difference between the heights of the longest and the shortest tower 
after modifications and output this difference.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {4, 6};
    int n = sizeof(arr)/sizeof(int);
    int k = 10;

    sort(arr, arr+n);

    int minEl, maxEl;
    int result = arr[n-1] - arr[0];

    for (int i=1; i<n; i++)
    {
        if (arr[i] >= k && arr[n-1] >= k)
        {
            maxEl = max(arr[i-1] + k, arr[n-1] - k);
            minEl = min(arr[0] + k, arr[i] - k);

            result = min(result, maxEl - minEl);
        }
    }

    cout<<result;

    return 0;
}