#include <stdio.h>

struct node
{
    int data;
    struct node * next;
};

void splitInHalf(struct node * head, struct node * head1, struct node * head2)
{
    struct node * slow = head;
    struct node * fast = head;

    while (fast->next != head || fast->next->next != head)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    if (fast->next->next == head)
    {
        fast = fast->next;
    }

    head1 = head;

    if (head->next != head)
    {
        head2 = slow->next;
    }

    fast->next = slow->next;
    slow->next = head;
}

void insertToEmpty(int data)
{
    struct node * new = (struct node *)malloc(sizeof(struct node *));
    
    new->data = data;
    new->next = new;
    struct node * head = new;
}

void insertBegin(struct node * head, int data)
{
    if (head == NULL)
    {
        insertToEmpty(data);
    }
    
    struct node * new = (struct node *)malloc(sizeof(struct node *));
    new->data = data;
    new->next = head;

    while (head->next != head)
    {
        head = head->next;
    } 

    head->next = new;
    head = new;
}

void insertToEnd(struct node * head, int data)
{
    if (head == NULL)
    {
        insertToEmpty(data);
    }
    
    struct node * new = (struct node *)malloc(sizeof(struct node *));
    new->data = data;
    new->next = head;

    while (head->next != head)
    {
        head = head->next;
    }

    head->next = new;
}

void insertAfter(struct node * head, int data, int item)
{
    if (head == NULL)
    {
        insertToEmpty(data);
    }

    if (head->next == head)
    {
        insertToEnd(head, data);
    }

    struct node * new = (struct node *)malloc(sizeof(struct node *));
    new->data = data;

    while (head->data != item)
    {
        head = head->next;
    }

    new->next = head->next;
    head->next = new;
}

void delete(struct node * head, int data)
{
    if (head == NULL)
    {
        return;
    }

    if (head->next == head)
    {
        head = NULL;
        return;
    }

    struct node * curr = head;
    struct node * prev = (struct node *)malloc(sizeof(struct node *));

    while (curr->data != data)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr->next == head || curr == head)
    {
        prev->next = head;
        free(curr);
        return;
    }

    prev->next = curr->next;
    free(curr);
}


int main()
{   
    return 0;
}