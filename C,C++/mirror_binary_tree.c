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

void mirrorTree(struct node * root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        struct node * temp;
        mirrorTree(root->left);
        mirrorTree(root->right);

        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
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


int main()
{
    struct node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    inorder(root);
    printf("\n");
    mirrorTree(root);
    inorder(root);

    return 0;
}