#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "pwwkew";
    int n = s.length();

    int i = 0;
    int j = 0;
    unordered_map<char, int> m;
    int ans = INT_MIN;

    while (j < n)
    {
        m[s[j]]++;

        if (m.size() == j-i+1)
        {
            ans = max(ans, j-i+1);
            j++;
        }
        else
        {
            while (m.size() < j-i+1)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                {
                    m.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }

    cout<<ans;
    
    return 0;
}