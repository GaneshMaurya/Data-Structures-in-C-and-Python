/*
How to implement a stack which will support following operations in O(1) time complexity? 

1) push() which adds an element to the top of stack. 
2) pop() which removes an element from top of stack. 
3) findMiddle() which will return middle element of the stack. 
4) deleteMiddle() which will delete the middle element. 

Push and pop are standard stack operations. 
The important question is, whether to use a linked list or array for implementation of stack? 

Please note that, we need to find and delete middle element. Deleting an element from middle is not O(1) for array. 
Also, we may need to move the middle pointer up when we push an element and move down when we pop(). 
In singly linked list, moving middle pointer in both directions is not possible. 

The idea is to use Doubly Linked List (DLL). 
We can delete middle element in O(1) time by maintaining mid pointer. 
We can move mid pointer in both directions using previous and next pointers. 
Following is implementation of push(), pop() and findMiddle() operations. 
Implementation of deleteMiddle() is left as an exercise. 
If there are even elements in stack, findMiddle() returns the second middle element. 
For example, if stack contains {1, 2, 3, 4}, then findMiddle() would return 3. 
*/

#include <stdio.h>

struct node
{
    struct node * prev;
    int data;
    struct node * next;
};

struct node * top = NULL;
struct node * mid = NULL;
int count = 0;

void push(int data)
{
    struct node * new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->prev = NULL;

    if (top == NULL)
    {
        new->next = NULL;
        top = new;
        count++;
    }
    else
    {
        new->next = top;
        top = new;
        count++;
    }

    if (count == 1 || count == 2)
    {
        mid = top;
    }
    else
    {
        mid = top;
        while (count != count/2)
        {
            mid = mid->prev;
            count--;
        }
    }
}

void pop()
{
    struct node * temp;

    temp = top;
    top = top->next;
    top->prev = NULL;

    temp->next = NULL;
    count--;

    mid = mid->next;

    free(temp);
}

int findMiddle()
{
    if (count == 0)
    {
        printf("Stack is empty");
        return -1;
    }
    else
    {
        return mid->data;
    }
}

void deleteMiddle()
{
    struct node * temp = mid;

    mid = mid->next;

    mid->prev = temp->prev;
    temp->prev->next = mid;

    count--;

    free(temp);
}


int main()
{
    return 0;
}