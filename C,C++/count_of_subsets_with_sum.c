#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {2, 3, 5, 6, 8, 10};
    int n = sizeof(arr)/sizeof(int);
    int sum = 10;

    int dp[n+1][sum+1];

    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=sum; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0)
            {
                dp[i][j] = 0;
            }
            else if (j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int val = arr[i-1];
                if (j >= val)
                {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-val];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }

    printf("%d", dp[n][sum]);
    
    return 0;
}