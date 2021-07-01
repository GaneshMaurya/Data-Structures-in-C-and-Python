#include <stdio.h>

int top = -1;
#define MAX_SIZE 100
int stack[MAX_SIZE];

void push(int data)
{
    if (top >= MAX_SIZE)
    {
        return;
    }
    top++;
    stack[top] = data;
}

void pop()
{
    if (top <= -1)
    {
        return;
    }
    top--;
}

int main()
{
    int arr[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = sizeof(arr)/sizeof(int);

    int a[n];
    a[n-1] = -1;

    for (int i=0; i<n-1; i++)
    {
        while (top != -1 && arr[stack[top]] < arr[i])
        {
            a[stack[top]] = i - stack[top];
            pop();
        }
        push(i);
    }

    if (arr[n-2] > arr[n-1])
    {
        a[n-2] = -1;
    }
    else
    {
        a[n-2] = arr[n-1] - arr[n-2];
    }

    for (int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    
    return 0;
}