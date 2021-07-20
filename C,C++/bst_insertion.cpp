#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct node 
{
    int data;
    int height;
    struct node * left;
    struct node * right;
};

struct node * addNode(struct node * root, int data)
{
    if (root == NULL)
    {
        struct node * temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    else if (root->data > data)
    {
        root->left = addNode(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = addNode(root->right, data);
    }

    return root;
}

void topView(struct node * root)
{
    if (root == NULL)
    {
        return;
    }

    queue<struct node *> q;
    map<int, int> m;
    q.push(root);
    root->height = 0;

    while (!q.empty())
    {
        struct node * temp = q.front();
        q.pop();
        int h = temp->height;

        if (m.find(h) == m.end())
        {
            m.insert({h, temp->data});
        }

        if (temp->left != NULL)
        {
            temp->left->height = h-1;
            q.push(temp->left);
        }

        if (temp->right != NULL)
        {
            temp->right->height = h+1;
            q.push(temp->right);
        }
    }

    map<int, int>::iterator itr;
    for (itr = m.begin(); itr != m.end(); itr++)
    {
        cout<<itr->second<<" ";
    }
}


int main()
{
    struct node * root = NULL;
    root = addNode(root, 30);
    addNode(root, 20);
    addNode(root, 40);
    addNode(root, 70);
    addNode(root, 60);
    addNode(root, 80);

    topView(root);
    
    return 0;
}