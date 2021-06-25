#include <stdio.h>

int main()
{
    int arr[] = {7, 9, 11, 12, 5};
    int l = sizeof(arr)/sizeof(int);
    int min = arr[0];
    int j = 0;

    for (int i=0; i<l; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            j = i;
        }
    }
    
    printf("%d", j);

    return 0;
}