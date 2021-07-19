#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define V 4
int visited[V];
int dfsvisited[V];
vector<int> adj[V];
stack<int> s;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

bool detectCycleUtil(int i)
{
    if (!visited[i])
    {
        visited[i] = 1;
        dfsvisited[i] = 1;

        for (auto itr = adj[i].begin(); itr != adj[i].end(); itr++)
        {
            if (!visited[*itr] && detectCycleUtil(*itr))
            {
                return true;
            }
            else if (dfsvisited[*itr])
            {
                return true;
            }
        }
    }

    dfsvisited[i] = 0;
    return false;
}

void detectCycle()
{
    for (int i=0; i<V; i++)
    {
        if (!visited[i])
        {
            if (detectCycleUtil(i))
            {
                cout<<"True";
                return;
            }
        }
    }

    cout<<"False";
    return;
}

int main()
{
    for (int i=0; i<V; i++)
    {
        visited[i] = 0;
        dfsvisited[i] = 0;
    }

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    detectCycle();

    return 0;
}