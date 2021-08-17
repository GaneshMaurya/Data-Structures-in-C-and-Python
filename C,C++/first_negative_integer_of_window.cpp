#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr)/sizeof(int);
    int k = 3;

    queue<int> q;
    vector<int> ans;
    int i = 0;
    int j = 0;

    while (j < n)
    {
        if (arr[j] < 0)
        {
            q.push(arr[j]);
        }
        
        if (j-i+1 < k)
        {
            j++;
        }
        else if (j-i+1 == k)
        {
            if (q.size() == 0)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(q.front());
            }

            if (arr[i] == q.front())
            {
                q.pop();
            }

            i++;
            j++;
        }
    }

    for (int x=0; x<ans.size(); x++)
    {
        cout<<ans[x]<<" ";
    }
    
    return 0;
}