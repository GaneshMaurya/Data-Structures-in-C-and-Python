#include <bits/stdc++.h>
using namespace std;

string reverseString(string str, int n)
{
    string res = "";
    for (int i=n-1; i>=0; i--)
    {
        res += str[i];
    }
    return res;
}

int minDeletion(string str1, int n)
{
    string str2 = reverseString(str1, n);
    int dp[n+1][n+1];

    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<n+1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i=1; i<n+1; i++)
    {
        for (int j=1; j<n+1; j++)
        {
            if (str1[i-1] == str2[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return n-dp[n][n];
}

int main()
{
    string s = "agbcba";
    int n = s.length();

    cout<<minDeletion(s, n);
    return 0;
}