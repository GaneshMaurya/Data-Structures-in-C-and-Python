#include <bits/stdc++.h>
using namespace std;

string reverseString(string s, int n)
{
    string res = "";
    for (int i = 0; i < n; i++)
    {
        res = s[i] + res;
    }
    return res;
}

int minNoOfInsertions(string s1, int n)
{
    int dp[n + 1][n + 1];
    string s2 = reverseString(s1, n);
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return s1.length() - dp[n][n];
}

int main()
{
    string s = "aebcbda";
    int n = s.length();

    cout << minNoOfInsertions(s, n);
    return 0;
}