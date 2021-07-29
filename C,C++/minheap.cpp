/* Min Heap Implementation */

#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

vector<int> minHeap;


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int minimum(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
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
    minHeap.push_back(data);
    int i = minHeap.size()-1;

    while (i != 0 && minHeap[parent(i)] > minHeap[i])
    {
        swap(&minHeap[parent(i)], &minHeap[i]);
        i = parent(i);
    }
}

int extractMin()
{
    if (minHeap.empty())
    {
        return INT_MAX;
    }
    if (minHeap.size() == 1)
    {
        int x = minHeap[0];
        minHeap.pop_back();
        return x;
    }

    int root = minHeap[0];
    minHeap[0] = minHeap[minHeap.size()-1];
    minHeap.pop_back();
    int i = 0;

    while (2*i+1 < minHeap.size())
    {
        int child;
        if (minHeap[leftChild(i)] < minHeap[rightChild(i)])
        {
            child = leftChild(i);
        }
        else
        {
            child = rightChild(i);
        }

        if (minHeap[i] > minHeap[child])
        {
            swap(&minHeap[i], &minHeap[child]);
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
    if (minHeap.empty())
    {
        cout<<"Empty Heap"<<"\n";
        return;
    }
    
    for (int i=0; i<minHeap.size(); i++)
    {
        cout<<minHeap[i]<<" ";
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
    
    int min = extractMin();
    cout<<min<<"\n";
    printHeap();
    
    min = extractMin();
    cout<<min<<"\n";
    printHeap();
    
    min = extractMin();
    cout<<min<<"\n";
    printHeap();
    
    min = extractMin();
    cout<<min<<"\n";
    printHeap();

    min = extractMin();
    cout<<min<<"\n";
    printHeap();

    min = extractMin();
    cout<<min<<"\n";
    printHeap();
    
    return 0;
}