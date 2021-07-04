/*
Given a Queue consisting of first n natural numbers (in random order). 
The task is to check whether the given Queue elements can be arranged in increasing order in another Queue using a stack. 

The operation allowed are:
1. Push and pop elements from the stack
2. Pop (Or enqueue) from the given Queue.
3. Push (Or Dequeue) in the another Queue.
*/

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

queue<int> q;
stack<int> s;

bool check()
{
    int x = 1;
    int k;

    int n = q.size();
    
    while (!q.empty())
    {
        k = q.front();
        q.pop();

        if (k == x)
        {
            x++;
        }
        else
        {
            if (s.empty())
            {
                s.push(k);
            }
            else if (!s.empty() && k > s.top())
            {
                return false;
            }
            else
            {
                s.push(k);
            }
        }

        while (!s.empty() && s.top() == x)
        {
            s.pop();
            x++;
        }
    }

    if (x-1 == n && s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    
    cout<<check();   
    
    return 0;
}