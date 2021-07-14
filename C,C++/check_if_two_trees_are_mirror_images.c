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

void mirror(struct node * root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        struct node * temp = (struct node *)malloc(sizeof(struct node));
        mirror(root->left);
        mirror(root->right);

        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }    
}

bool isSame(struct node * root1, struct node * root2)
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
        return (root1->data == root2->data && isSame(root1->left, root2->left) && isSame(root1->right, root2->right));
    }
}


int main()
{
    struct node * root1 = newNode(2);
    root1->left = newNode(7);
    root1->left->left = newNode(5);
    root1->right = newNode(8);

    struct node * root2 = newNode(2);
    root2->right = newNode(7);
    root2->right->right = newNode(5);
    root2->left = newNode(8);

    mirror(root1);

    if (isSame(root1, root2))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    
    return 0;
}