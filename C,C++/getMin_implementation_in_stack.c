#include <stdio.h>

#define MAX_SIZE 100
int top = -1;
int stack[MAX_SIZE];
int min;

void push(int x)
{
    if (top == -1)
    {
        top++;
        stack[top] = x;
        min = x;
    }
    else
    {
        if (x > min)
        {
            top++;
            stack[top] = x;
        }
        else
        {
            top++;
            stack[top] = 2*x-min;
            min = x;
        }
    }
}

void pop()
{
    if (stack[top] >= min)
    {
        top--;
    }
    else
    {
        min = 2*min - stack[top];
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
        printf("%d ", min);
    }
}


int main()
{
    push(1);
    push(2);
    push(3);
    push(0);
    getMin();
    pop();
    getMin();
    
    return 0; 
}