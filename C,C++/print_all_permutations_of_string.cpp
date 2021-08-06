#include <bits/stdc++.h>
using namespace std;

void printAllPermutations(string str, set<string> &ans, string result)
{
    if (str.length() == 0)
    {
        ans.insert(result);
        return;
    }

    for (int i=0; str[i] != '\0'; i++)
    {
        char ch = str[i];
        string lpart = str.substr(0, i);
        string rpart = str.substr(i+1);
        string remaining = lpart + rpart;
        printAllPermutations(remaining, ans, result + ch);
    }
}


int main()
{
    string str = "aB3";
    set<string> ans;
    printAllPermutations(str, ans, "");

    for (auto itr = ans.begin(); itr != ans.end(); itr++)
    {
        cout<<*itr<<"\n";
    }
    
    return 0;
}