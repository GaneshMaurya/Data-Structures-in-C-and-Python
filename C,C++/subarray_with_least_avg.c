#include <stdio.h>

int main()
{
    int arr[] = {3, 7, 90, 20, 10, 50, 40};
    int n = sizeof(arr)/sizeof(int);
    int k = 3;

    int first = 0;

    for (int i=0; i<k; i++)
    {
        first += arr[i];
    }

    int prev = first;
    int next, min = prev;

    int j = k-1;

    for (int i=k; i<n; i++)
    {
        next = prev + arr[i] - arr[i-k];
        if (next < min)
        {
            min = next;
            j = i;
        }
        prev = next;
    }

    printf("%d\n", min);

    for (int i=k; i>0; i--)
    {
        printf("%d ", arr[j-i+1]);
    }
    
    return 0;
}