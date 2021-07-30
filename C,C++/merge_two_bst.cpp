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

void inorderTree(struct node * root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    inorderTree(root->left, v);
    v.push_back(root->data);
    inorderTree(root->right, v);
}

void mergeArrays(vector<int> &in1, vector<int> &in2, vector<int> &in3)
{
    for (int i=0; i<in1.size(); i++)
    {
        in3.push_back(in1[i]);
    }
    for (int i=0; i<in2.size(); i++)
    {
        in3.push_back(in2[i]);
    }
}

struct node * buildBSTUtil(vector<int> &in3, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = (start+end)/2;
    struct node * temp = NULL;
    temp = insert(temp, in3[mid]);

    temp->left = buildBSTUtil(in3, start, mid-1);
    temp->right = buildBSTUtil(in3, mid+1, end);

    return temp;
}

struct node * buildBST(struct node * root, vector<int> v)
{
    int n = v.size();
    return buildBSTUtil(v, 0, n-1);
}


int main()
{   
    struct node * root1 = NULL;
    root1 = insert(root1, 3);
    insert(root1, 2);
    insert(root1, 4);
    insert(root1, 1);

    struct node * root2 = NULL;
    root2 = insert(root2, 6);
    insert(root2, 5);
    insert(root2, 7);

    vector<int> in1, in2, in3;
    inorderTree(root1, in1);
    inorderTree(root2, in2);

    mergeArrays(in1, in2, in3);
    sort(in3.begin(), in3.end());

    struct node * root3 = NULL;
    root3 = buildBST(root3, in3);

    printTree(root3);
    
    return 0;
}