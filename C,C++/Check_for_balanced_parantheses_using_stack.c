#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 101

char stack[MAX_SIZE];
int top = -1;

void Push(char c) 
{
    if (top > MAX_SIZE) {
        printf("Overflow.");
        return;
    }
    ++top;
    stack[top] = c;
}

void Pop()
{
    if (top <= -1) {
        printf("Underflow.");
        return;
    }
    top--;
}

bool arePair(char a, char b)
{
    if (a == '(' && b == ')') {
        return true;
    }
    else if (a == '[' && b == ']') {
        return true;
    }
    else if (a == '{' && b == '}') {
        return true;
    }
    else {
        return false;
    }
}

bool areBalanced(char c[])
{
    for (int i=0; i<strlen(c); i++)
    {
        if (c[i] == '(' || c[i] == '[' || c[i] == '{')
        {
            Push(c[i]);
        }
        else if (c[i] == ')' || c[i] == ']' || c[i] == '}')
        {
            if (top == -1 || !(arePair(stack[top], c[i])))
            {
                return false;
            }
            else 
            {
                Pop();
            }
        }    
    }

    if (top == -1) 
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
    char c[50];
    printf("Enter the expression : ");
    gets(c);

    if (areBalanced(c))
    {
        printf("Balanced Equation.");
    }
    else 
    {
        printf("Unbalanced Equation.");
    }
    
    return 0;
}