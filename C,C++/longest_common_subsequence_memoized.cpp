#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int LCS(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }

    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    if (x[n-1] == y[m-1])
    {
        dp[n][m] = 1 + LCS(x, y, n-1, m-1);
        return dp[n][m];
    }
    else
    {
        dp[n][m] = max(LCS(x, y, n-1, m), LCS(x, y, n, m-1));
        return dp[n][m];
    }
}

int main()
{
    string x = "abcdgh";
    string y = "abedfhr";
    int n = x.length();
    int m = y.length();

    memset(dp, -1, sizeof(dp));
    cout<<LCS(x, y, n, m);

    return 0;
}