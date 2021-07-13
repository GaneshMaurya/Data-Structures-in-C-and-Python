#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperand(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c<= '9'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int prec(char a)
{
    if (a == '^')
    {
        return 3;
    }
    else if (a == '*' || a == '/')
    {
        return 2;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixtopostfix(string exp)
{
    stack<char> s;
    string result = "";

    for (int i=0; exp[i]!='\0'; i++)
    {
        if (isOperand(exp[i]))
        {
            result = result + exp[i];
        }
        else if (exp[i] == '(')
        {
            s.push('(');
        }
        else if (exp[i] == ')')
        {
            while (s.top() != '(')
            {
                result = result + s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && prec(exp[i]) <= prec(s.top()))
            {
                result = result + s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
    }

    while (!s.empty())
    {
        result = result + s.top();
        s.pop();
    }

    return result;
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout<<infixtopostfix(exp);
    return 0;
}