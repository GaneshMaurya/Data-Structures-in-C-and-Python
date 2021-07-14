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

int getWidthOfLevel(struct node * root, int level)
{
    if (root == NULL)
    {
        return 0;
    }

    if (level == 1)
    {
        return 1;
    } 

    return getWidthOfLevel(root->left, level-1) + getWidthOfLevel(root->right, level-1);
}


int main()
{
    struct node * root = newNode(2);
    root->left = newNode(7);
    root->right = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left = newNode(5);
    root->left->right->left->left = newNode(10);
    root->left->right->right = newNode(11);
    root->right->right = newNode(9);

    int level = 3;
    int res = getWidthOfLevel(root, level);

    cout<<res;
    
    return 0;
}