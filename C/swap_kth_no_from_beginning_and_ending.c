/*Given a singly linked list, swap kth node from beginning with kth node from end. 
Swapping of data is not allowed, only pointers should be changed. 
This requirement may be logical in many situations where the linked list data part is huge 
(For example student details line Name, RollNo, Address, ..etc). 
The pointers are always fixed (4 bytes for most of the compilers).*/

/*
Y is next to X
X is next to Y
X and Y are same
X and Y don’t exist (k is more than number of nodes in linked list)
*/

#include <stdio.h>

struct node 
{
    int data;
    struct node * next;
};

void swap(struct node * head, int k)
{
    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        return;
    }

    int n = 0;

    struct node * temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        n++;
    }

    if (n < k)
    {
        return;
    }

    if (2*k-1 == n)
    {
        return;
    }

    int countf = 0;
    int countb = 0;

    struct node * x = head;
    struct node * x_prev = NULL;
    struct node * y = head;
    struct node * y_prev = NULL;

    while (countf != k)
    {
        x_prev = x;
        x = x->next;
        countf++;
    }

    while (countb != n-k+1)
    {
        y_prev = y;
        y = y->next;
        countb++;
    }

    if (x_prev) 
    {
        x_prev->next = y;
    }

    if (y_prev) 
    {
        y_prev->next = x;
    }

    temp = x->next;
    x->next = y->next;
    y->next = temp;

    if (k == 1)
    {
        head = y;
    }
    else
    {
        head = x;
    }
}


int main()
{
    return 0;
}