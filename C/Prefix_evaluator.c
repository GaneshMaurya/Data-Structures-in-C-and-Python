#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

void Push(int x)
{
    if (top > SIZE-1) {
        printf("Overflow \n");
    }
    else {
        ++top;
        stack[top] = x;
    }
}

int Pop()
{
    if (top < 0) {
        printf("Underflow \n");
    }
    else {
        int item = stack[top];
        top--;
        return item;
    }
}

void PostfixOperation(char c[])
{
    for (int i=0; i<strlen(c); i++)
    {
        if (isdigit(c[i]))
        {
            Push(c[i]-'0');
        }
        else if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/')
        {
            if (c[i] == '+')
            {
                int op1 = Pop();
                int op2 = Pop();
                int res = op2 + op1;
                Push(res);
            }
            else if (c[i] == '-')
            {
                int op1 = Pop();
                int op2 = Pop();
                int res = op2 - op1;
                Push(res);
            }
            else if (c[i] == '*')
            {
                int op1 = Pop();
                int op2 = Pop();
                int res = op2 * op1;
                Push(res);
            }
            else if (c[i] == '/')
            {
                int op1 = Pop();
                int op2 = Pop();
                int res = op2 / op1;
                Push(res);
            }
        }
        else 
        {
            printf("Invalid Expression.");
        }
    }
    int result = Pop();
    printf("%d", result);
}

int main()
{
    char c[100];
    printf("Enter the infix expression : ");
    gets(c);

    int i = 0;
    int j = strlen(c)-1;

    for (int k=i; k<j; k++)
    {
        int temp = c[i];
        c[i] = c[j];
        c[j] = temp;
        i++;
        j--;
    }

    PostfixOperation(c);
    
    return 0;
}