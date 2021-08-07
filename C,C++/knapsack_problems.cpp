#include <bits/stdc++.h>
using namespace std;

int main()
{
    float p[] = {10, 5, 15, 7, 6, 18, 3};
    float w[] = {2, 3, 5, 7, 1, 4, 1};
    int n = sizeof(p)/sizeof(float);
    int total = 15;
    
    vector <pair<float, int>> v;
    for (int i=0; i<n; i++)
    {
        float x = p[i]/w[i];
        v.push_back({x, i});
    }
    sort(v.begin(), v.end(), greater<pair<float, int>>());

    int s = 0;
    float ans = 0;

    for (int i=0; i<n; i++)
    {
        if (s + w[v[i].second] < total)
        {
            s += w[v[i].second];
            ans += p[v[i].second];
        }
        else
        {
            float x = total - s;
            ans += x*v[i].first;
            break;
        }
    }
    cout<<ans;

    return 0;
}