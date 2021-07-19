#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define V 10
int visited[V];
vector<int> adj[V];
stack<int> s;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void topologicalSortUtil(int node)
{
    visited[node] = 1;
    
    for (auto itr = adj[node].begin(); itr != adj[node].end(); itr++)
    {
        if (!visited[*itr])
        {
            topologicalSortUtil(*itr);
        }
    }

    s.push(node);
}

void topologicalSort()
{
    for (int i=0; i<V; i++)
    {
        if (!visited[i])
        {
            topologicalSortUtil(i);
        }
    }

    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}


int main()
{
    for (int i=0; i<V; i++)
    {
        visited[i] = 0;
    }

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 5);
    addEdge(adj, 6, 0);
    addEdge(adj, 6, 1);
    addEdge(adj, 6, 2);
    addEdge(adj, 1, 7);
    addEdge(adj, 8, 2);
    addEdge(adj, 3, 7);
    addEdge(adj, 3, 2);
    addEdge(adj, 3, 8);
    addEdge(adj, 3, 4);
    addEdge(adj, 9, 4);
    addEdge(adj, 4, 8);

    // addEdge(adj, 5, 2);
    // addEdge(adj, 5, 0);
    // addEdge(adj, 4, 0);
    // addEdge(adj, 4, 1);
    // addEdge(adj, 2, 3);
    // addEdge(adj, 3, 1);

    topologicalSort();

    return 0;
}