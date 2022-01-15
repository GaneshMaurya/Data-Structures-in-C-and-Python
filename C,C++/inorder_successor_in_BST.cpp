#include <bits/stdc++.h>
using namespace std;

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

struct node * insertNode(struct node * root, int data)
{
    if (root == NULL)
    {
        return newNode(data);
    }
    else
    {
        if (data > root->data)
        {
            root->right = insertNode(root->right, data);
        }
        else
        {
            root->left = insertNode(root->left, data);
        }

        return root;
    }
}

void inorder(struct node * root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);

        return;
    }
}

struct node * inorderSuccessor(struct node * root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        root = root->right;
        while (root->left != NULL)
        {
            root = root->left;
        }
    }

    return root;
}


int main()
{
    struct node * root = NULL;
    root = insertNode(root, 40);
    root = insertNode(root, 20);
    root = insertNode(root, 60);
    root = insertNode(root, 10);
    root = insertNode(root, 30);
    root = insertNode(root, 50);
    root = insertNode(root, 70);

    inorder(root);
    cout<<"\n";
    
    cout<<inorderSuccessor(root, 10)->data;

    return 0;
}