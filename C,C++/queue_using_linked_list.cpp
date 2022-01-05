#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void listTraversal()
{
    struct Node * temp = front;
    if (temp == NULL)
    {
        cout<<"Queue is empty.\n";
        return;
    }
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
    return;
}

bool isEmpty()
{
    if (front == NULL)
    {
        return true;
    }
    return false;
}

bool isFull()
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node *));
    if (temp == NULL)
    {
        return true;
    }
    return false;
}

void enqueue(int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        cout<<"Queue is full.\n";
    }
    else
    {
        temp->data = val;
        temp->next = NULL;
        cout<<"Element enqueued : "<<temp->data<<"\n";
        if (front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
    return;
}

void dequeue()
{
    if (front == NULL)
    {
        cout<<"Queue is empty.\n";
    }
    else
    {
        struct Node * temp = front;
        front = front->next;
        cout<<"Element dequeued : "<<temp->data<<"\n";
        free(temp);
    }
}

int main()
{
    listTraversal();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    listTraversal();
    dequeue();
    dequeue();
    listTraversal();

    return 0;
}