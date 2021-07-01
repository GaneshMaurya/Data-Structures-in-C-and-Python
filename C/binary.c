#include <stdio.h>
#include <stdlib.h>

int top = -1;
#define MAX_SIZE 100

int stack[MAX_SIZE];

void push(int stack[], int data)
{
    if (top >= MAX_SIZE-1)
    {
        return;
    }
    top++;
    stack[top] = data;
}

void pop(int stack[])
{
    if (top == -1)
    {
        return;
    }
    top--;
}

void showStack(int stack[])
{
    int i = top;
    while (i != -1)
    {
        printf("%d ", stack[i]);
        i--;
    }
}

void binary(int n)
{
    if (n == 0)
    {
        return;
    }
    
    while (n != 0)
    {
        push(stack, n%2);
        n = n/2;
    }
}


int main()
{
    binary(0);
    showStack(stack);

    return 0;
}