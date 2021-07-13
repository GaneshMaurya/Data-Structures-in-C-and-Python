#include <iostream>
#include <stack>
using namespace std;

string prefixtoinfix(string exp)
{
    stack<string> s;

    for (int i=exp.length()-1; i>=0; i--)
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
            temp = '(' + op1 + exp[i] + op2 + ')';
            s.push(temp);
        }
    }

    return s.top(); 
}

int main()
{
    string exp = "*-A/BC-/AKL";
    cout<<prefixtoinfix(exp);
    return 0;
}