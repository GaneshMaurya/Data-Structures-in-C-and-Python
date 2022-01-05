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

void enqueueLast(int val)
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
        cout<<"Element enqueued in last : "<<temp->data<<"\n";
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

void enqueueFront(int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        cout<<"Queue is full.\n";
    }
    else
    {
        temp->data = val;
        cout<<"Element enqueued in front : "<<temp->data<<"\n";
        if (front == NULL)
        {
            temp->next = NULL;
            front = temp;
            rear = temp;
        }
        else
        {
            temp->next = front;
            front = temp;
        }
    }
    return;
}

void dequeueFront()
{
    if (front == NULL)
    {
        cout<<"Queue is empty.\n";
    }
    else
    {
        struct Node * temp = front;
        front = front->next;
        cout<<"Element dequeued from front : "<<temp->data<<"\n";
        free(temp);
    }
}

void dequeueLast()
{
    if (front == NULL)
    {
        cout<<"Queue is empty.\n";
    }
    else
    {
        struct Node * temp = front;
        while (temp->next != rear)
        {
            temp = temp->next;
        }
        cout<<"Element dequeued from last : "<<rear->data<<"\n";
        temp->next = NULL;
        rear = temp;
        free(temp);
    }
}

int main()
{
    listTraversal();
    enqueueLast(1);
    enqueueLast(2);
    enqueueFront(3);
    enqueueFront(4);
    listTraversal();
    dequeueLast();
    dequeueFront();
    listTraversal();

    return 0;
}