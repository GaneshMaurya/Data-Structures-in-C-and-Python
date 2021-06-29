#include <stdio.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node * next;
};

void Insert(struct Node * head, int data)
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));

    struct Node * new = (struct Node *)malloc(sizeof(struct Node));
    
    if (head == NULL)
    {
        head->data = data;
        head->next = NULL;
        head = new;
    }
    
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    new->data = data;
    temp->next = new;
}

void InsertAfter(struct Node * prev, int data)
{
    struct Node * new = (struct Node *)malloc(sizeof(struct Node));

    new->data = data;

    if (prev == NULL)
    {
        return;
    }

    new->next = prev->next;
    prev->next = new;
}

void DeleteList(struct Node * head)
{
    if (head == NULL)
    {
        return;
    }

    while (head->next != NULL)
    {
        DeleteList(head->next);
    }

    free(head);
}

int Length(struct Node * head)
{
    int count = 0;
    
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + Length(head->next);
    }
}

bool search(struct Node * head, int data)
{
    if (head == NULL)
    {
        return false;
    }
    else 
    {
        while (head->next != NULL)
        {
            if (head->data == data)
            {
                return true;
            }
            head = head->next;
        }
    }
    return false;
}

int Get_Nth(struct Node * head, int index)
{
    int count = 0;

    while (head->next != NULL)
    {
        if (count == index)
        {
            return head->data;
        }
        head = head->next;
        count++;
    }

    return count;
}

int Get_Nth_End(struct Node * head, int n)
{
    struct Node * main = head;
    struct Node * ref = head;

    for (int i=0; i<n-1; i++)
    {
        ref = ref->next;
    }

    while (ref->next != NULL)
    {
        ref = ref->next;
        main = main->next;
    }

    return main->data;
}

int Get_Middle(struct Node * head)
{
    struct Node * fast = head;
    struct Node * slow = head;

    while (fast->next != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

void swap(struct Node * head, int x, int y)
{
    if (x == y)
    {
        return;
    }
    
    struct Node * prevX = NULL;
    struct Node * currX = head;

    while (currX && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }

    struct Node * prevY = NULL;
    struct Node * currY = head;

    while (currY && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    if (prevX != NULL)
    {
        prevX->next = currY;
    }
    else
    {
        head = currY;
    }

    if (prevY != NULL)
    {
        prevY->next = currX;
    }
    else
    {
        head = currX;
    }

    struct Node * temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

void reverse(struct Node * head)
{
    struct Node * prev = NULL;
    struct Node * curr = head;
    struct Node * next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = curr;
}


int main()
{
    
    
    return 0;
}