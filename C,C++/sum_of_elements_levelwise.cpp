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

void levelwiseSum(struct node * root)
{
    if (root == NULL)
    {
        return;
    }

    queue<struct node *> q;
    q.push(root);

    while(true)
    {
        int size = q.size();
        if (size == 0)
        {
            break;
        }
        int sum = 0;
        while (size > 0)
        {
            struct node * temp = q.front();
            q.pop();

            sum += temp->data;

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }    

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }

            size--;
        }
        cout<<sum<<endl;
    }
    return;
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
    
    levelwiseSum(root);

    return 0;
}