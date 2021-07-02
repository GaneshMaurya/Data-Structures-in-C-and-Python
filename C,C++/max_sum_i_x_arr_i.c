#include <stdio.h>

int main()
{
    int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(int);

    int arrSum = 0;
    int curval = 0;

    for (int i=0; i<n; i++)
    {
        arrSum = arrSum + arr[i];
        curval = curval + i*arr[i];
    }

    int maxval = curval;

    for (int i=1; i<n; i++)
    {
        curval = arrSum - n*arr[n-i] + curval;
        if (curval > maxval)
        {
            maxval = curval;
        }
    }

    printf("%d", maxval);

    return 0;
}