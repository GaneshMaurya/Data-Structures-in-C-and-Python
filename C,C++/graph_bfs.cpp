#include <bits/stdc++.h>
using namespace std;

int main()
{
    int adjacent_matrix[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    queue<int> q;
    int start = 0;
    visited[start] = 1;
    cout<<start<<" ";
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int j=0; j<7; j++)
        {
            if (adjacent_matrix[node][j] == 1 && visited[j] == 0)
            {
                cout<<j<<" ";
                visited[j] = 1;
                q.push(j);
            }
        }
    }

    return 0;
}