#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define V 5
int visited[V];
vector<int> adj[V];

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void search_dfs(int node, int n)
{
    visited[node] = 1;

    stack<int> s;
    s.push(node);

    while (!s.empty())
    {
        int top = s.top();
        s.pop();

        if (!visited[top])
        {
            visited[top] = 1;

            if (top == n)
            {
                cout<<"Found"<<endl;
                return;
            }
        }

        for (auto itr = adj[top].begin(); itr != adj[top].end(); itr++)
        {
            if (!visited[*itr])
            {
                s.push(*itr);
            }
        }
    }

    cout<<"Not Found"<<endl;
    return;
}

void search_bfs(int node, int n)
{
    queue<int> q;

    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        if (!visited[front])
        {
            visited[front] = 1;
            if (front == n)
            {
                cout<<"Found"<<endl;
                return;
            }
        }

        for (auto itr = adj[front].begin(); itr != adj[front].end(); itr++)
        {
            if (!visited[*itr])
            {
                q.push(*itr);
            }
        }
    }

    cout<<"Not Found"<<endl;
    return;
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

    //search_dfs(0, 19);
    search_bfs(0, 2);
    
    return 0;
}