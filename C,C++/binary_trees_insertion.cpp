#include <iostream>
#include <queue>
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

void insert(struct node * root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
        return;
    }

    queue <struct node *> q;
    q.push(root);

    while (!q.empty())
    {
        struct node * temp = q.front();
        q.pop();

        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        else
        {
            temp->left = newNode(data);
            return;
        }

        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
        else
        {
            temp->right = newNode(data);
            return;
        }        
    }
    exit(0);
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


int main()
{
    struct node * root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);
    inorder(root);
    printf("\n");

    insert(root, 12);
    inorder(root);
    printf("\n");
    
    return 0;
}