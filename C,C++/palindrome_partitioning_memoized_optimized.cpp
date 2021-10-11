/*
Palindrome Partitioning

Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. 
For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. 
Determine the fewest cuts needed for a palindrome partitioning of a given string. 
For example, minimum of 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”. 
If a string is a palindrome, then minimum 0 cuts are needed. 
If a string of length n containing all different characters, then minimum n-1 cuts are needed. 

*/

#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

bool isPalindrome(string s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int palindromePartitioning(string s, int i, int j)
{
    if (i >= j)
    {
        return 0;
    }

    if (isPalindrome(s, i, j))
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = INT_MAX;
    int left;
    int right;

    for (int k=i; k<j; k++)
    {
        if (dp[i][k] != -1)
        {
            left = dp[i][k];
        }
        else
        {
            left = palindromePartitioning(s, i, k);
            dp[i][k] = left;
        }

        if (dp[k+1][j] != -1)
        {
            right = dp[k+1][j];
        }
        else
        {
            right = palindromePartitioning(s, k+1, j);
            dp[k+1][j] = right;
        }

        int temp = 1 + left + right;
        ans = min(ans, temp);
        
        dp[i][j] = ans;
    }

    return ans;
}

int main()
{
    string s = "abcbd";
    int n = s.length();
    memset(dp, -1, sizeof(dp));
    cout<<palindromePartitioning(s, 0, n-1);
    return 0;
}