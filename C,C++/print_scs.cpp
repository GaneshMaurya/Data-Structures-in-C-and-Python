/*

Printing Shortest Common Supersequence

Given two strings X and Y, print the shortest string that has both X and Y as subsequences. 
If multiple shortest supersequence exists, print any one of them.

Examples: 

Input: X = "AGGTAB",  Y = "GXTXAYB"
Output: "AGXGTXAYB" OR "AGGXTXAYB" 
OR Any string that represents shortest
supersequence of X and Y

Input: X = "HELLO",  Y = "GEEK"
Output: "GEHEKLLO" OR "GHEEKLLO"
OR Any string that represents shortest 
supersequence of X and Y

*/

#include <bits/stdc++.h>
using namespace std;

string printSCS(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();

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
            if (str1[i-1] == str2[i-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string res = "";
    int i = n;
    int j = m;
    
    while (i > 0 && j > 0)
    {
        if (str1[i-1] == str2[j-1])
        {
            res = str1[i-1] + res;
            i--;
            j--;
        }
        else
        {
            if (dp[i-1][j] > dp[i][j-1])
            {
                res = str1[i-1] + res;
                i--;
            }
            else
            {
                res = str2[j-1] + res;
                j--;
            }
        }
    }

    while (i > 0)
    {
        res = str1[i-1] + res;
        i--;
    }

    while (j > 0)
    {
        res = str2[j-1] + res;
        j--;
    }

    return res;
}

int main()
{
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
    
    cout<<printSCS(str1, str2);
    return 0;
}