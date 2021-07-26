#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * insert(struct node * root, int data)
{
    if (root == NULL)
    {
        struct node * temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }
    else if (root->data <= data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        root->left = insert(root->left, data);
    }

    return root;
}

void inorder(struct node * root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

struct node * maxElement(struct node * root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }

    return root;
}

struct node * deleteNode(struct node * root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (root->data > data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            struct node * temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            struct node * temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            struct node * temp = maxElement(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
        }
    }
    return root;
}

int main()
{
    struct node * root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 90);

    inorder(root);
    cout<<"\n";
    root = deleteNode(root, 90);
    root = deleteNode(root, 80);
    root = deleteNode(root, 50);
    inorder(root);

    return 0;
}