#include <stdio.h>

#define MAX_SIZE 100
int top = -1;
int stack[MAX_SIZE];
int max;

void push(int x)
{
    if (top == -1)
    {
        top++;
        stack[top] = x;
        max = x;
    }
    else
    {
        if (x < max)
        {
            top++;
            stack[top] = x;
        }
        else
        {
            top++;
            stack[top] = 2*x-max;
            max = x;
        }
    }
}

void pop()
{
    if (stack[top] <= max)
    {
        top--;
    }
    else
    {
        max = 2*max - stack[top];
        top--;
    }
}

void getMin()
{
    if (top == -1)
    {
        printf("Empty stack");
    }
    else
    {
        printf("%d ", max);
    }
}


int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    getMin();
    pop();
    getMin();
    
    return 0; 
}