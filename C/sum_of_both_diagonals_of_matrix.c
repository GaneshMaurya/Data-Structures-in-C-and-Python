#include <stdio.h>

#define MAX 100

void sumOfDiagonals(int matrix[][MAX], int n)
{
    int sum = 0;
    for (int i=0; i<n; i++)
    {
        sum += matrix[i][i] + matrix[i][n-i-1];
    }

    if (n%2 != 0)
    {
        sum = sum - matrix[n/2][n/2];
    }

    printf("%d", sum);
}

int main()
{
    int matrix[][MAX] = { { 2, 5, 7 },
                          { 3, 7, 2 }, 
                          { 5, 6, 9 } };

    int r = sizeof(matrix)/sizeof(matrix[0]);
    //int c = sizeof(matrix)/sizeof(matrix[0][0]);
    sumOfDiagonals(matrix, r);
    return 0;
}