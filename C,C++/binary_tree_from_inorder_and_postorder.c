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

struct node * buildTreeHelper(int in[], int post[], int inS, int inE, int postS, int postE)
{
    if (inS > inE)
    {
        return NULL;
    }

    int rootData = post[postE];
    struct node * root = newNode(rootData);

    if (inS == inE)
    {
        return root;
    }

    int rootIndex = -1;

    for (int i=inS; i<=inE; i++)
    {
        if (rootData == in[i])
        {
            rootIndex = i;
            break;
        }
    }

    int linS = inS;
    int linE = rootIndex - 1;
    int rinS = rootIndex + 1;
    int rinE = inE;

    int lpostS = postS;
    int lpostE = linE - linS + lpostS;
    int rpostS = lpostE + 1;
    int rpostE = postE - 1;

    root->right = buildTreeHelper(in, post, rinS, rinE, rpostS, rpostE);
    root->left = buildTreeHelper(in, post, linS, linE, lpostS, lpostE);
    
    return root;
}

struct node * buildTree(int in[], int post[], int size)
{
    return buildTreeHelper(in, post, 0, size-1, 0, size-1);
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

void preorder(struct node * root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node * root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}


int main()
{
    int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    int post[] = {4, 5, 2, 8, 9, 6, 7, 3, 1};
    int size = sizeof(in)/sizeof(int);

    struct node * root = buildTree(in, post, size);

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    
    return 0;
}