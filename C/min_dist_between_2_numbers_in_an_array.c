/*Given an unsorted array arr[] and two numbers x and y, find the minimum distance between x and y in arr[]. 
The array might also contain duplicates. 
You may assume that both x and y are different and present in arr[].*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
    int arr[] = {2, 5, 3, 5, 4, 4, 2, 3};
    int n = sizeof(arr)/sizeof(int);

    int x = 3;
    int y = 2;

    int min_dist = INT_MAX;
    int p = 0;

    for (int i=0; i<n; i++)
    {
        if (arr[i] == x || arr[i] == y)
        {
            if (arr[i] == arr[p])
            {
                p = i;
            }
            else
            {
                if (min_dist > abs(i-p))
                {
                    min_dist = abs(i-p);
                }
            }
        }
    }

    printf("%d", min_dist);

    return 0;
}