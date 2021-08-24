#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr)/sizeof(int);
    int k = 3;
    
    int i = 0;
    int j = 1;
    int maxi = arr[0];
    list<int> l;
    l.push_back(arr[0]);

    while (j < n)
    {
        if (arr[j] > l.front())
        {
            while (!l.empty() && arr[j] > l.front())
            {
                l.pop_back();
            }
            l.push_back(arr[j]);
        }  
        
        if (j-i+1 < k)
        {
            j++;
        }
        else if (j-i+1 == k)
        { 
            cout<<l.front()<<" ";

            if (l.front() == arr[i])
            {
                l.pop_front();
            }
            i++;
            j++;
        }
    }

    return 0;
}