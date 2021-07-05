#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (l <= r)
    {
        int mid = l + (r-l)/2;

        if (arr[mid] == x)
        {
            return mid;
        }

        if (arr[mid] > x)
        {
            return binarySearch(arr, l, mid, x);
        }
        else if (arr[mid] < x)
        {
            return binarySearch(arr, mid+1, r, x);
        }
    }
    return -1;
}


int main()
{
    int arr[] = {1, 2, 3, 6, 4, 8, 10};
    int n = sizeof(arr)/sizeof(int);

    int l = 0;
    int r = n-1;

    int res = binarySearch(arr, l, r, 6);
    
    printf("%d", res);

    return 0;
}