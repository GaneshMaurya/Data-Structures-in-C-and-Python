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
    // return (int)stack[top];
    top--;
}


int main()
{
    char c[50];
    printf("Enter the expression : ");
    gets(c);

    int op1, op2;

    for (int i=0; i< strlen(c); i++)
    {
        if (c[i] != '+' || c[i] != '-' || c[i] != '*' || c[i] != '/')
        {
            Push(c[i]);
        }
        else 
        {
            if (c[i] == '+')
            {
                op1 = stack[top];
                Pop();
                op2 = stack[top];
                Pop();
                Push((char)(op1+op2));
            }
            else if (c[i] == '-')
            {
                op1 = stack[top];
                Pop();
                op2 = stack[top];
                Pop();
                Push((char)(op1-op2));
            }
            else if (c[i] == '*')
            {
                op1 = stack[top];
                Pop();
                op2 = stack[top];
                Pop();
                Push((char)(op1*op2));
            }
            else if (c[i] == '/')
            {
                op1 = stack[top];
                Pop();
                op2 = stack[top];
                Pop();
                Push((char)(op1/op2));
            }
            else {
                printf("Invalid expression.");
                break;
            }
        }
    }

    int res = (int)stack[top];
    printf("%d", res);

    return 0;
}