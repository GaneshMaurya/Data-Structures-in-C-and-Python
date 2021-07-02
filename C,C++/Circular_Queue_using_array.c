#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

bool isEmpty(int queue[])
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool isFull(int queue[])
{
    if (((rear+1)%MAX_SIZE) == front)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void Enqueue(int x)
{
    if (isFull(queue))
    {
        printf("Queue is full.");
    }
    else if (isEmpty(queue))
    {
        front++;
        rear++;
        queue[rear] = x;
    }
    else 
    {
        rear = (rear+1)%MAX_SIZE;
        queue[rear] = x;
    }
}

void Dequeue()
{
    if (isEmpty(queue))
    {
        printf("Cannot perform dequeue on an empty queue.");
    }
    else if (front == rear) 
    {
        front = -1;
        rear = -1;
    }
    else 
    {
        front = (front+1)%MAX_SIZE;
    }
}

void Front()
{
    printf("%d \n", queue[front]);
}

int main()
{
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    Dequeue();
    Front();
    Dequeue();
    Front();

    return 0;
}