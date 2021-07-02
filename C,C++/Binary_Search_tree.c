#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node 
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * GetNewNode(int data)
{
    struct node * new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
    
}

struct node * Insert(struct node * root, int data)
{   
    if (root == NULL)
    {
        root = GetNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    
    return root;
}

bool Search(struct node * root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return Search(root->left, data);
    }
    else 
    {
        return Search(root->right, data);
    }
}

int main()
{
    struct node * root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);

    int x = 30;
    if (Search(root, x))
    {
        printf("Found.");
    }
    else 
    {
        printf("Not Found.");
    }

    return 0;
}