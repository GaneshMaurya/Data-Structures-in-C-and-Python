#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define V 6
int visited[V];
vector<int> adj[V];

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool hasPath(int source, int dest)
{
    if (source == dest)
    {
        return true;
    }

    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        if (!visited[front])
        {
            visited[front] = 1;
        }

        for (auto itr = adj[front].begin(); itr != adj[front].end(); itr++)
        {
            if (*itr == dest)
            {
                return true;
            }

            if (!visited[*itr])
            {
                q.push(*itr);
            }
        }
    }

    return false;
}


int main()
{
    for (int i=0; i<V; i++)
    {
        visited[i] = 0;
    }

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 4, 6);
    
    if(hasPath(3, 5))
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }

    return 0;
}