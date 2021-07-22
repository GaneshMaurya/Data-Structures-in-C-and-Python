#include <iostream>
#include <limits.h>
using namespace std;

// int maxi = INT_MIN;

struct node 
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * addNode(int data)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int maximum(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int getMaxSumSubtreeUtil(struct node * root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }

    int curSum = root->data + getMaxSumSubtreeUtil(root->left, ans) + getMaxSumSubtreeUtil(root->right, ans);
    ans = maximum(ans, curSum);

    return curSum;
}

int getMaxSumSubtree(struct node * root)
{
    if (root == NULL)
    {
        return 0;
    }

    int ans = INT_MIN;

    getMaxSumSubtreeUtil(root, ans);

    return ans;
}

// int getMaxSumSubtree(struct node * root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     int ans = root->data + getMaxSumSubtree(root->left) + getMaxSumSubtree(root->right);
//     maxi = maximum(maxi, ans);

//     return ans;
// }

int main()
{
    struct node * root = (struct node *)malloc(sizeof(struct node));
    root = addNode(1);
    root->left = addNode(-2);
    root->right = addNode(3);
    root->left->left = addNode(4);
    root->left->right = addNode(5);
    root->right->left = addNode(-6);
    root->right->right = addNode(2000);

    cout<<getMaxSumSubtree(root);
    
    return 0;
}