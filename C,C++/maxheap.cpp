/* Max Heap */

#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000

int maxHeap[SIZE];
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
    maxHeap[heapSize] = data;
    heapSize++;
    int i = heapSize-1;

    while (i != 0 && maxHeap[parent(i)] < maxHeap[i])
    {
        swap(&maxHeap[parent(i)], &maxHeap[i]);
        i = parent(i);
    }
}

int extractMax()
{
    if (heapSize < 0)
    {
        return INT_MAX;
    }
    if (heapSize == 1)
    {
        int x = maxHeap[0];
        heapSize--;
        return x;
    }

    int root = maxHeap[0];
    maxHeap[0] = maxHeap[heapSize-1];
    heapSize--;
    int i = 0;

    while (2*i+1 < heapSize)
    {
        int child;
        if (maxHeap[leftChild(i)] > maxHeap[rightChild(i)])
        {
            child = leftChild(i);
        }
        else
        {
            child = rightChild(i);
        }

        if (maxHeap[i] < maxHeap[child])
        {
            swap(&maxHeap[i], &maxHeap[child]);
            i = child;
        }
        else
        {
            break;
        }
    }

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
        cout<<maxHeap[i]<<" ";
    }
    cout<<"\n";
}


int main()
{
    insertHeap(12);
    insertHeap(15);
    insertHeap(11);
    insertHeap(30);
    insertHeap(5);
    insertHeap(6);
    printHeap();

    int min = extractMax();
    cout<<min<<"\n";
    printHeap();
    
    min = extractMax();
    cout<<min<<"\n";
    printHeap();
    
    min = extractMax();
    cout<<min<<"\n";
    printHeap();
    
    min = extractMax();
    cout<<min<<"\n";
    printHeap();

    min = extractMax();
    cout<<min<<"\n";
    printHeap();

    min = extractMax();
    cout<<min<<"\n";
    printHeap();
    
    return 0;
}