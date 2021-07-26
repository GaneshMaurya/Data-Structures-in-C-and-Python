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
    else if (root->data > data)
    {
        root->left = insert(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = insert(root->right, data);
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

void preorder(struct node * root)
{
    if (root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int preIndex = 0;

struct node * constructBSTUtil(int pre[], int min, int max, int size)
{
    if (preIndex > size)
    {
        return NULL;
    }

    struct node * root = NULL;
    int data = pre[preIndex];

    if (data > min && data < max)
    {
        root = newNode(data);
        preIndex += 1;

        if (preIndex < size)
        {
            root->left = constructBSTUtil(pre, min, data, size);
        }
        if (preIndex < size)
        {
            root->right = constructBSTUtil(pre, data, max, size);
        }
    }

    return root;
}

struct node * constructBST(int pre[], int size)
{
    return constructBSTUtil(pre, INT_MIN, INT_MAX, size);
}

int main()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(pre)/sizeof(int);

    // O(n^2)
    struct node * root1 = NULL;
    for (int i=0; i<size; i++)
    {
        root1 = insert(root1, pre[i]);
    }

    // O(n)
    struct node * root2 = constructBST(pre, size);

    preorder(root1);
    cout<<"\n";
    preorder(root2);

    return 0;
}