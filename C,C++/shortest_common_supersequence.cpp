/*
Shortest Common Supersequence

Given two strings str1 and str2, the task is to find the length of the shortest string 
that has both str1 and str2 as subsequences.

Examples : 

Input:   str1 = "geek",  str2 = "eke"
Output: 5
Explanation: 
String "geeke" has both string "geek" 
and "eke" as subsequences.

Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
Output:  9
Explanation: 
String "AGXGTXAYB" has both string 
"AGGTAB" and "GXTXAYB" as subsequences.
*/

#include <bits/stdc++.h>
using namespace std;

int SCS(string a, string b)
{
    int n = a.length();
    int m = b.length();

    int dp[n+1][m+1];

    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<m+1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i=1; i<n+1; i++)
    {
        for (int j=1; j<m+1; j++)
        {
            if (a[i-1] == b[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return m + n - dp[n][m];
}

int main()
{
    string a = "AGGTAB";
    string b = "GXTXAYB";

    cout<<SCS(a, b);
    
    return 0;
}