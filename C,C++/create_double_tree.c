#include <stdio.h>
#include <stdlib.h>

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

void inorder(struct node * root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void doubletree(struct node * root)
{
    if (root == NULL)
    {
        return;
    }

    doubletree(root->left);
    doubletree(root->right);

    struct node * temp = newNode(root->data);
    temp->left = root->left;
    root->left = temp;
}


int main()
{
    struct node * root = newNode(2);
    root->left = newNode(7);
    root->right = newNode(8);

    inorder(root);
    doubletree(root);
    printf("\n");
    inorder(root);
    
    return 0;
}