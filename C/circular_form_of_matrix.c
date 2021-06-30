#include <stdio.h>

#define MAX 100

int main()
{
    int mat[][MAX] = { { 2, 5, 7 },
                       { 3, 7, 2 }, 
                       { 5, 6, 9 },
                       { 12, 3, 10}};

    int r = 4;
    int c = 3;

    for (int i=0; i<r; i++)
    {
        if (i%2 == 0)
        {
            for (int j=0; j<c; j++)
            {
                printf("%d ", mat[i][j]);
            }
        }
        else
        {
            for (int k=c-1; k>=0; k--)
            {
                printf("%d ", mat[i][k]);
            }
        }
    }
    
    return 0;
}