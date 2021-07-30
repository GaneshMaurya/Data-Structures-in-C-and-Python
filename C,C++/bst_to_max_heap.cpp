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

void postorder_tree(struct node * root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    postorder_tree(root->right, v);
    v.push_back(root->data);
    postorder_tree(root->left, v);
}

void bstToMaxHeap(struct node * root, vector<int> v, int &i)
{
    if (root == NULL)
    {
        return;
    }

    root->data = v[i];
    i++;
    bstToMaxHeap(root->right, v, i);
    bstToMaxHeap(root->left, v, i);
}


int main()
{
    struct node * root = NULL;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 6);
    insert(root, 1);
    insert(root, 3);
    insert(root, 5);
    insert(root, 7);

    printTree(root);
    cout<<"\n";

    vector<int> v;
    postorder_tree(root, v);

    int i = 0;
    bstToMaxHeap(root, v, i);
    printTree(root);
    
    return 0;
}