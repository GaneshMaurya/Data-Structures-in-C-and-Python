#include <stdio.h>

int maximum(int a, int b)
{
    return a >= b ? a : b;
}

int main()
{
    int array[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(array)/sizeof(int);

    int curr_max = array[0];
    int max_so_far = array[0];

    for (int i=0; i<n; i++)
    {
        curr_max = maximum(array[i], curr_max + array[i]);
        max_so_far = maximum(max_so_far, curr_max);
    }

    printf("%d", max_so_far);

    return 0;
}