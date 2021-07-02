/*Given an array with all distinct elements, find the largest three elements. 
Expected time complexity is O(n) and extra space is O(1). */

#include <stdio.h>
#include <limits.h>

int main()
{
    int arr[] = {12, 13, 1, 10, 34, 1};
    int n = sizeof(arr)/sizeof(int);

    int first = INT_MIN;
    int second = INT_MIN;
    int third = INT_MIN;

    for (int i=0; i<n; i++)
    {
        if (arr[i] > first && arr[i] > second && arr[i] > third)
        {
            third = second;
            second = first;
            first = arr[i];
        }
        else if (arr[i] <= first && arr[i] > second && arr[i] > third)
        {
            third = second;
            second = arr[i];
        }
        else if (arr[i] <= first && arr[i] <= second && arr[i] > third)
        {
            third = arr[i];
        }
    }

    printf("%d %d %d", first, second, third);
    
    return 0;
}