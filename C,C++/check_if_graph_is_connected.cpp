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

    for (auto itr = adj[node].begin(); itr != adj[node].end(); itr++)
    {
        if (!visited[*itr])
        {
            dfs(*itr);
        }
    }
}

bool isConnected()
{
    dfs(0);

    for (int i=0; i<V; i++)
    {
        if (visited[i] != 1)
        {
            return false;
        }
    }

    return true;
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

    if (isConnected())
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
    
    return 0;
}