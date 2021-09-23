#include <bits/stdc++.h>
using namespace std;

#define R1 4
#define C1 4
#define R2 4
#define C2 4

void multiply(int A[][C1], int B[][C2])
{
    int C[R1][C1];

    for (int i=0; i<R1; i++)
    {
        for (int j=0; j<C1; j++)
        {
            C[i][j] = 0;
            for (int k=0; k<C1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
            cout<<C[i][j]<<" ";
        }
        cout<<"\n";
    }

    return;
}

int main()
{
    int A[R1][C1] = {
            {1, 1, 1, 1},
            {2, 2, 2, 2},
            {3, 3, 3, 3},
            {4, 4, 4, 4}
    };
 
    int B[R2][C2] = {
            {1, 1, 1, 1},
            {2, 2, 2, 2},
            {3, 3, 3, 3},
            {4, 4, 4, 4}
    };

    multiply(A, B);

    return 0;
}