#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }

    int dp[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    int res = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                res = max(res, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return res;
}

int main()
{
    string x = "GeeksforGeeks";
    string y = "GeeksQuiz";
    int n = x.length();
    int m = y.length();

    cout << longestCommonSubstring(x, y, n, m);

    return 0;
}