/*
Approach: This solution requires modifications to the basic linked list data structure. 

- Have a visited flag with each node.
- Traverse the linked list and keep marking visited nodes.
- If you see a visited node again then there is a loop. 
  This solution works in O(n) but requires additional information with each node.
- A variation of this solution that doesn’t require modification to basic data
  structure can be implemented using a hash, just store the addresses of visited nodes in a 
  hash and if you see an address that already exists in hash then there is a loop.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node * next;
    int flag;
};

struct node * head = NULL;

void insert(int data)
{
    struct node * new = (struct node *)malloc(sizeof(struct node));
    
    new->data = data;
    new->next  = NULL;
    new->flag = 0;
    
    if (head == NULL)
    {
        head = new;
        return;
    }
    else
    {
        struct node * temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new;
    }
}

bool checkLoop()
{
    struct node * temp = head;

    while (temp != NULL)
    {
        if (temp->flag == 1)
        {
            return true;
        }

        temp->flag = 1;
        temp = temp->next;
    }
    return false;
}


int main()
{
    insert(20);
    insert(4);
    insert(15);
    insert(10);

    head->next->next->next->next = head;

    bool result = checkLoop();

    if (result)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    
    return 0;
}