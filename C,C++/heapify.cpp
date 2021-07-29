/* Heapify Algorithm */
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define SIZE 1000
int minHeap[SIZE];
int heapSize = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int i)
{
    return (i-1)/2;
}

int leftChild(int i)
{
    return 2*i+1;
}

int rightChild(int i)
{
    return 2*i+2;
}

void insertHeap(int data)
{
    minHeap[heapSize] = data;
    heapSize++;
}

void Heapify(int i)
{
    int l = leftChild(i);
    int r = rightChild(i);
    int smallest = i;

    if (l < heapSize && minHeap[l] < minHeap[i])
    {
        smallest = l;
    }
    if (r < heapSize && minHeap[r] < minHeap[smallest])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(&minHeap[i], &minHeap[smallest]);
        Heapify(smallest);
    }
}

int extractMin()
{
    if (heapSize <= 0)
    {
        return INT_MAX;
    }
    if (heapSize == 1)
    {
        int x = minHeap[0];
        heapSize--;
        return x;
    }

    int root = minHeap[0];
    minHeap[0] = minHeap[heapSize-1];
    heapSize--;
    Heapify(0);

    return root;
}

void printHeap()
{
    if (heapSize <= 0)
    {
        cout<<"Empty Heap"<<"\n";
        return;
    }
    
    for (int i=0; i<heapSize; i++)
    {
        cout<<minHeap[i]<<" ";
    }
    cout<<"\n";
}


int main()
{
    insertHeap(100);
    insertHeap(30);
    insertHeap(20);
    insertHeap(35);
    insertHeap(40);
    insertHeap(32);
    insertHeap(25);
    Heapify(0);

    printHeap();

    cout<<extractMin()<<"\n";
    printHeap();

    cout<<extractMin()<<"\n";
    printHeap();
    
    return 0;
}