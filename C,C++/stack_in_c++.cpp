#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    cout<< " " << stack.size();
    cout<<"\n";

    cout<< " " << stack.top();
    cout<<"\n";

    stack.pop();
    stack.pop();

    cout<< " " << stack.size();
    cout<<"\n";

    cout<< " " << stack.top();
    stack.pop();
    cout<< " " << stack.top();
}