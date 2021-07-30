/* Given a Binary Tree, convert it to a Binary Search Tree. 
The conversion must be done in such a way that keeps the original structure of Binary Tree.  */

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

void inorder_tree(struct node * root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    inorder_tree(root->left, v);
    v.push_back(root->data);
    inorder_tree(root->right, v);
}

void inorder_bst(struct node * root, vector<int> v, int &i)
{
    if (root == NULL)
    {
        return;
    }

    inorder_bst(root->left, v, i);
    root->data = v[i];
    i++;
    inorder_bst(root->right, v, i);
}


int main()
{
    struct node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    vector<int> v;
    inorder_tree(root, v);

    printTree(root);
    cout<<"\n";

    sort(v.begin(), v.end());

    int i = 0;
    inorder_bst(root, v, i);
    printTree(root);
    
    return 0;
}