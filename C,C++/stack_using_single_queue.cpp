#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

void PushStack(int x)
{
    int s = q.size();
    q.push(x);

    for (int i=0; i<s; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

void PopStack()
{
    q.pop();
}


int main()
{
    
}