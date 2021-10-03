/*

Minimum number of deletions and insertions to transform one string into another

Given two strings ‘str1’ and ‘str2’ of size m and n respectively. 
The task is to remove/delete and insert the minimum number of characters from/in str1 to transform it into str2. 
It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted 
to some another point.

Example 1: 

Input : 
str1 = "heap", str2 = "pea" 
Output : 
Minimum Deletion = 2 and
Minimum Insertion = 1

Explanation:
p and h deleted from heap
Then, p is inserted at the beginning
One thing to note, though p was required yet
it was removed/deleted first from its position and
then it is inserted to some other position.
Thus, p contributes one to the deletion_count
and one to the insertion_count.

*/

#include <bits/stdc++.h>
using namespace std;

void printMinDelAndInsert(string str1, string str2)
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
            if (str1[i-1] == str2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout<<"Deletions required = "<<n-dp[n][m]<<endl;
    cout<<"Insertions required = "<<m-dp[n][m]<<endl;
}

int main()
{
    string str1 = "heap";
    string str2 = "pea";

    printMinDelAndInsert(str1, str2);
    return 0;
}