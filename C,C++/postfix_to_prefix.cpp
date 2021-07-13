#include <iostream>
#include <stack>
using namespace std;

string postToPre(string exp)
{
    stack<string> s;

    for (int i=0; i<exp.length(); i++)
    {
        if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= '0' && exp[i] <= '9'))
        {
            string x = "";
            x += exp[i];
            s.push(x);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = exp[i] + op2 + op1;
            s.push(temp);
        }
    }

    return s.top();
}

int main()
{
    string exp = "AB+CD-*";
    cout<<postToPre(exp);
    return 0;
}