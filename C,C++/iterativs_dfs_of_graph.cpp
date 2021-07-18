#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define V 5
int visited[V];
vector<int> adj[V];

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs_iter(int node)
{
    stack<int> s;
    s.push(node);

    while (!s.empty())
    {
        int top = s.top();
        s.pop();

        if (visited[top] == 0)
        {
            cout<<top<<" ";
            visited[top] = 1;
        }

        for (auto itr = adj[top].begin(); itr != adj[top].end(); itr++)
        {
            if (visited[*itr] == 0)
            {
                s.push(*itr);
            }
        }
    }
}

int main()
{
    for (int i=0; i<V; i++)
    {
        visited[i] = 0;
    }

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 4, 3);
    
    dfs_iter(2);

    return 0;
}