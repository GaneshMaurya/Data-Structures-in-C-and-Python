#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node 
{
    struct node * left;
    int data;
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

void Preorder(struct node * root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d\t", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

int main()
{
    struct node * root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 35);
    root = Insert(root, 5);
    root = Insert(root, 25);
    root = Insert(root, 0);
    root = Insert(root, -5);
    root = Insert(root, 45);

    Preorder(root);

    return 0;
}