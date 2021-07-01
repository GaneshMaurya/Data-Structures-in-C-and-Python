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




int main()
{   
    return 0;
}