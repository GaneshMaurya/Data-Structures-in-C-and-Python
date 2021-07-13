#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPrefix(string exp)
{
    stack<char> s;
    string result = "";

    for (int i=exp.length()-1; i>=0; i--)
    {
        if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= '0' && exp[i] <= '9'))
        {
            result += exp[i];
        }
        else if (exp[i] == ')')
        {
            s.push(exp[i]);
        }
        else if (exp[i] == '(')
        {
            while (s.top() != ')')
            {
                result += s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && prec(exp[i]) <= prec(s.top()))
            {
                result += s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
    }

    while (!s.empty())
    {
        result += s.top();
        s.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string exp = "(A-B/C)*(A/K-L)";
    cout<<infixToPrefix(exp);
    return 0;
}