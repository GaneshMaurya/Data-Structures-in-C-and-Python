#include <iostream>
#include <queue>
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

void bfs(int node)
{
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        
        if (!visited[front])
        {
            visited[front] = 1;
            cout<<front<<" ";
        }

        for (auto itr = adj[front].begin(); itr != adj[front].end(); itr++)
        {
            if (!visited[*itr])
            {
                q.push(*itr);
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

    bfs(2);
    
    return 0;
}