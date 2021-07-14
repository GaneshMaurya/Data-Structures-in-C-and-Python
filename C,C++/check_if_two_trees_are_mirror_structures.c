#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node 
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * newNode(int data)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

bool isMirrorStructure(struct node * root1, struct node * root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    else
    {
        return (isMirrorStructure(root1->left, root2->right) && isMirrorStructure(root1->right, root2->left));
    }
}


int main()
{
    struct node * root1 = newNode(2);
    root1->left = newNode(7);
    root1->left->left = newNode(5);
    root1->right = newNode(8);

    struct node * root2 = newNode(3);
    root2->right = newNode(5);
    root2->right->right = newNode(9);
    root2->left = newNode(10);

    if (isMirrorStructure(root1, root2))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    
    return 0;
}