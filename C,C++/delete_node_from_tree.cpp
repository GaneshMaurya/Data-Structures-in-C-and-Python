#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node  * newNode(int data)
{
    struct node * lastNode = (struct node *)malloc(sizeof(struct node));

    lastNode->data = data;
    lastNode->left = NULL;
    lastNode->right = NULL;

    return lastNode;
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

void deleteNode(struct node * root, int key)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == key)
        {
            free(root);
            root = NULL;
            return;
        }
        else
        {
            return;
        }
    }

    queue<struct node *> q;
    q.push(root);

    struct node * lastNode;
    struct node * keyNode;
    struct node * pl;
    struct node * pr;

    while (!q.empty())
    {
        lastNode = q.front();
        q.pop();

        if (lastNode->data == key)
        {
            keyNode = lastNode;
        }

        if (lastNode->left != NULL)
        {
            q.push(lastNode->left);
            pl = lastNode;
            pr = NULL;
        }

        if (lastNode->right != NULL)
        {
            q.push(lastNode->right);
            pr = lastNode;
            pl = NULL;
        }
    }

    if (keyNode != NULL)
    {
        keyNode->data = lastNode->data;
        
        if (pl != NULL)
        {
            free(lastNode);
            pl->left = NULL;
        }
        else
        {
            free(lastNode);
            pr->right = NULL;
        }
        return;
    }
    else
    {
        return;
    }
}

int main()
{
    struct node * root = newNode(1);
    root->left  = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->left->right = newNode(6);
    root->right->left = newNode(5);

    inorder(root);
    cout<<"\n";
    deleteNode(root, 1);
    inorder(root);
    
    return 0;
}