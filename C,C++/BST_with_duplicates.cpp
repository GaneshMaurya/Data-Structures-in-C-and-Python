#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    int count;
    struct node * left;
    struct node * right;
};

struct node * insert(struct node * root, int data)
{
    if (root == NULL)
    {
        struct node * temp = (struct node *)malloc(sizeof(struct node));

        temp->data = data;
        temp->count = 1;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }
    
    if (root->data == data)
    {
        root->count += 1;
    }
    
    if (root->data > data)
    {
        root->left = insert(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

struct node * getMax(struct node * root)
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
        return NULL;
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
        if (root->count > 1)
        {
            root->count -= 1;
            return root;
        }
        
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
            struct node * temp = getMax(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
        }
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


int main()
{
    struct node * root = NULL;
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 9);
    root = insert(root, 11);
    root = insert(root, 12);
    root = insert(root, 12);
    root = insert(root, 10);

    inorder(root);
    cout<<"\n";

    root = deleteNode(root, 12);
    root = deleteNode(root, 12);
    root = deleteNode(root, 12);

    inorder(root);
    
    return 0;
}