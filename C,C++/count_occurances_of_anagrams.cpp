#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "aabaabaa";
    string p = "aaba";
    int k = p.length();
    int n = s.length();

    int i = 0;
    int j = 0;
    int ans = 0;

    unordered_map<char, int> m;
    for (int i=0; i<k; i++)
    {
        m[p[i]]++;
    }
    int count = m.size();

    while (j < n)
    {
        if (m.find(s[j]) != m.end())
        {
            m[s[j]]--;

            if (m[s[j]] == 0)
            {
                count--;
            }
        }

        if (j-i+1 < k)
        {
            j++;
        }
        else if (j-i+1 == k)
        {
            if (count == 0)
            {
                ans++;
            }

            if (m.find(s[i]) != m.end())
            {
                m[s[i]]++;
                if (m[s[i]] == 1)
                {
                    count++;
                }
            }

            i++;
            j++;
        }    
    }

    cout<<ans;
    
    return 0;
}