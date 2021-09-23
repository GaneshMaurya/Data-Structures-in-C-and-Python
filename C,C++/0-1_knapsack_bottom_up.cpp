#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int W, int n)
{
    vector<vector<int>> dp(n+1, vector<int>(W+1));
    
    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<W+1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] == 0;
            }
        }
    }

    for (int i=1; i<n+1; i++)
    {
        for (int j=1; j<W+1; j++)
        {
            if (wt[i-1] <= j)
            {
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int wt[] = {1, 3, 4, 5};
    int val[] = {9, 4, 5, 7};
    int W = 10;
    int n = sizeof(wt)/sizeof(int);

    cout<<knapsack(wt, val, W, n);
    
    return 0;
}