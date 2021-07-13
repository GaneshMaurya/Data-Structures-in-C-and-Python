#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node  * left;
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

struct node * buildeTreeHelper(int in[], int pre[], int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }

    int rootData = pre[preS];
    int rootIndex = -1;

    struct node * root = newNode(rootData);

    if (inS == inE)
    {
        return root;
    }

    for (int i=inS; i<=inE; i++)
    {
        if (rootData == in[i])
        {
            rootIndex = i;
            break;
        }
    }

    int lInS = inS;
    int lInE = rootIndex - 1;
    int rInS = rootIndex + 1;
    int rInE = inE;

    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;
    int rPreS = lPreE + 1;
    int rPreE = preE;

    root->left = buildeTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildeTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);

    return root;
}

struct node * buildTree(int in[], int pre[], int size)
{
    return buildeTreeHelper(in, pre, 0, size-1, 0, size-1);
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


int main()
{
    int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    int size = sizeof(in)/sizeof(in[0]);

    struct node * root = buildTree(in, pre, size);

    inorder(root);
    printf("\n");
    preorder(root);
    
    return 0;
}