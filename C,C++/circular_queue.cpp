#include <bits/stdc++.h>
using namespace std;

struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

bool isEmpty(struct circularQueue *q)
{
    if (q->f == q->r)
    {
        return true;
    }
    return false;
}

bool isFull(struct circularQueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return true;
    }
    return false;
}

void enqueue(struct circularQueue *q, int val)
{
    if ((q->r + 1) % q->size == q->f)
    {
        cout << "Queue is full.\n";
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        cout << "Element enqueued : " << val << ".\n";
    }
    return;
}

void dequeue(struct circularQueue *q)
{
    if (q->f == q->r)
    {
        cout << "Queue is empty.\n";
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        int val = q->arr[q->f];
        cout << "Element dequeued is : " << val << ".\n";
    }
}

int main()
{
    struct circularQueue q;
    q.size = 5;
    q.f = 0;
    q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    if (isEmpty(&q))
    {
        cout<<"Queue is empty.\n";
    }
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    if (isFull(&q))
    {
        cout<<"Queue is full.\n";
    }
    enqueue(&q, 5);
    if (isFull(&q))
    {
        cout<<"Queue is full.\n";
    }
    dequeue(&q);
    dequeue(&q);

    return 0;
}