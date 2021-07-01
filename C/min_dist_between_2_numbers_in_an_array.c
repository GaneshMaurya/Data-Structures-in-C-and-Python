/*Given an unsorted array arr[] and two numbers x and y, find the minimum distance between x and y in arr[]. 
The array might also contain duplicates. 
You may assume that both x and y are different and present in arr[].*/

#include <stdio.h>
#include <limits.h>

int minimum(int a, int b)
{
    if (a>b)
        return b;
    return a;
}

int main()
{
    int arr[] = {3, 5, 4, 2, 6, 3, 0, 0, 5, 4, 8, 3};
    int n = sizeof(arr)/sizeof(int);
    int x = 3;
    int y = 6;

    int p = -1;
    int min_dist = INT_MAX;

    for (int i=0; i<n; i++)
    {
        if (arr[i] == x || arr[i] == y)
        {
            if (p != -1 && arr[i] != arr[p])
            {
                min_dist = minimum(min_dist, i-p);
            }
            p = i;
        }
    }

    if (min_dist == INT_MAX)
    {
        min_dist = -1;
    }

    printf("%d", min_dist);
    
    return 0;
}