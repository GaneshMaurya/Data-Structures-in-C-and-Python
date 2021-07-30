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

    if (root->data > data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

void printTree(struct node * root)
{
    if (root == NULL)
    {
        return;
    }

    printTree(root->left);
    cout<<root->data<<" ";
    printTree(root->right);
}

void inorder_tree(struct node * root, vector<struct node *> &v)
{
    if (root == NULL)
    {
        return;
    }

    inorder_tree(root->left, v);
    v.push_back(root);
    inorder_tree(root->right, v);
}

struct node * buildBalancedTreeUtil(vector<struct node *> &v, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start+end)/2;
    struct node * root = v[mid];

    root->left = buildBalancedTreeUtil(v, start, mid-1);
    root->right = buildBalancedTreeUtil(v, mid+1, end);

    return root;
}

struct node * buildBalancedTree(vector<struct node *> &v)
{
    int n = v.size();
    return buildBalancedTreeUtil(v, 0, n-1);
}


int main()
{
    struct node * root1 = NULL;
    root1 = insert(root1, 7);
    insert(root1, 6);
    insert(root1, 5);
    insert(root1, 4);
    insert(root1, 3);
    insert(root1, 2);
    insert(root1, 1);
    printTree(root1);
    cout<<"\n";
    
    vector<struct node *> v;
    inorder_tree(root1, v);

    struct node * root2 = buildBalancedTree(v);
    printTree(root2);

    return 0;
}