#include <stdio.h>

int main()
{
    int arr[] = {2, 7, 1, 4, 1, 7, 8, 2, 8};
    int n = sizeof(arr)/sizeof(int);

    for (int i=0; i<n; i++)
    {
        arr[arr[i]%n] += n;
    }

    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i=0; i<n; i++)
    {
        if (arr[i]/n > 1)
        {
            printf("%d ", arr[i]%n);
        }
    }

    return 0;
}