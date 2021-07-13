#include <iostream>
#include <stack>
using namespace std;

string postfixtoinfix(string exp)
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
        else if (exp[i] == '^' || exp[i] == '*' || exp[i] == '/' || exp[i] == '+' || exp[i] == '-')
        {
            string temp;
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            temp = '(' + op2 + exp[i] + op1 + ')';
            s.push(temp);
        }
    }

    return s.top(); 
}

int main()
{
    string exp = "ab*c+";
    cout<<postfixtoinfix(exp);
    return 0;
}