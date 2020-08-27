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

struct node * FindMin(struct node * root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct node * Delete(struct node * root, int x)
{
    if (root == NULL)
    {
        return root;
    }
    else if (x < root->data)
    {
        root->left = Delete(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = Delete(root->right, x);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            struct node * temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct node * temp = root;
            root = root->left;
            free(temp);
        }
        else 
        {
            struct node * temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

void Inorder(struct node * root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    printf("%d\t", root->data);
    Inorder(root->right);
}

int main()
{
    struct node * root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 5);
    root = Insert(root, 50);
    root = Insert(root, 0);
    root = Insert(root, 30);
    root = Insert(root, 35);
    Inorder(root);

    printf("\n");
    root = Delete(root, 25);
    Inorder(root);

    printf("\n");
    root = Delete(root, 15);
    Inorder(root);

    return 0;
}