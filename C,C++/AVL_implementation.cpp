#include <bits/stdc++.h>
using namespace std;

struct node 
{
    int data;
    struct node * left;
    struct node * right;
    int height;
};

int getHeight(struct node * root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

struct node * createNode(int data)
{
    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

int getBalanceFactor(struct node * root)
{
    if (root == NULL)
    {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

struct node * rightRotate(struct node * y)
{
    struct node * x = y->left;
    struct node * T2 = x->right;
    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

struct node * leftRotate(struct node * x)
{
    struct node * y = x->right;
    struct node * T2 = y->left;
    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return y;
}

struct node * insert(struct node * root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int bf = getBalanceFactor(root);

    // Left Left Case
    if (bf > 1 && data < root->left->data)
    {
        return rightRotate(root);
    }
    // Right Right Case
    if (bf < -1 && data > root->right->data)
    {
        return leftRotate(root);
    }
    // Left Right Rotate
    if (bf > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right Left Rotate
    if (bf < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
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

    return;
}

int main()
{
    struct node * root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    inorder(root);
    
    return 0;
}