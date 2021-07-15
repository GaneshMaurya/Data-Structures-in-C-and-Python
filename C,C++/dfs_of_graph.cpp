#include <iostream>
#include <vector>
using namespace std;

#define V 5
int visited[V];
vector<int> adj[V];

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node)
{
    visited[node] = 1;
    cout<<node<<" ";

    vector<int>::iterator itr;

    for (itr = adj[node].begin(); itr != adj[node].end(); itr++)
    {
        if (visited[*itr] == 0)
        {
            dfs(*itr);
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

    dfs(2);
    
    return 0;
}