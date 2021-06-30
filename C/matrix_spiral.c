#include <stdio.h>

#define r 3
#define c 6

void spiralPrint(int m, int n, int matrix[r][c])
{
    int k = 0;
    int l = 0;

    while (k < m && l < n)
    {
        for (int i=l; i<n; i++)
        {
            printf("%d ", matrix[k][i]);
        }
        k++;

        for (int i=k; i<m; i++)
        {
            printf("%d ", matrix[k][n-1]);
        }
        n--;

        if (k < m)
        {
            for (int i=n-1; i>=l; --i)
            {
                printf("%d ", matrix[m-1][i]);
            }
            m--;
        }

        if (l < n)
        {
            for (int i=m-1; i>=k; --i)
            {
                printf("%d ", matrix[i][l]);
            }
            l++;
        }
    }
}

int main()
{
    int matrix[r][c] = { { 1, 2, 3, 4, 5, 6 },
                       { 7, 8, 9, 10, 11, 12 },
                       { 13, 14, 15, 16, 17, 18 } };

    spiralPrint(r, c, matrix);
    return 0;
}