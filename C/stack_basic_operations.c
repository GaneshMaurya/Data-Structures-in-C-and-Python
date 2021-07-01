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


int main()
{
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);

    pop(stack);

    showStack(stack);

    

    return 0;
}