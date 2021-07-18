#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int arr[] = {2, 3, 5, 6, 8, 10};
    int n = sizeof(arr)/sizeof(int);
    int sum = 100;

    bool dp[n+1][sum+1];

    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=sum; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                dp[i][j] = false;
            }
            else if (j == 0)
            {
                dp[i][j] = true;
            }
            else
            {
                int val = arr[i-1];
                if (j >= val)
                {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-val];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }

    if (dp[n][sum])
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    
    return 0;
}