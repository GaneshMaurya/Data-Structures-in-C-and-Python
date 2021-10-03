/*
Printing Longest Common Subsequence

Given two sequences, print the longest subsequence present in both of them.

Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

Following is detailed algorithm to print the LCS. It uses the same 2D table L[][].

1) Construct L[m+1][n+1] using the steps discussed in previous post.

2) The value L[m][n] contains length of LCS. Create a character array lcs[] of length equal 
    to the length of lcs plus 1 (one extra to store \0).

3) Traverse the 2D array starting from L[m][n]. Do following for every cell L[i][j]

    .a) If characters (in X and Y) corresponding to L[i][j] are same (Or X[i-1] == Y[j-1]), 
    then include this character as part of LCS.
    .b) Else compare values of L[i-1][j] and L[i][j-1] and go in direction of greater value.
*/

#include <bits/stdc++.h>
using namespace std;

string printLCS(string a, string b)
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

    int i = n;
    int j = m;
    string res = "";

    while (i > 0 && j > 0)
    {
        if (a[i-1] == b[j-1])
        {
            res = a[i-1] + res;
            i--;
            j--;
        }
        else
        {
            if (dp[i][j-1] > dp[i-1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }

    return res;
}

int main()
{
    string a = "acbcf";
    string b = "abcaf";

    cout<<printLCS(a, b);
    
    return 0;
}