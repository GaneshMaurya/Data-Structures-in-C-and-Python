#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    struct ListNode * next;
};

struct TreeNode
{
    int data;
    struct TreeNode * left;
    struct TreeNode * right;
};

struct ListNode * insertList(struct ListNode * head, int data)
{
    if (head == NULL)
    {
        struct ListNode * temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->data = data;
        temp->next = NULL;

        head = temp;
        return head;
    }
    else
    {
        struct ListNode * temp = head;
        struct ListNode * newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->data = data;
        newNode->next = NULL;
        
        return head;
    }
}

struct TreeNode * newNode(int data)
{
    struct TreeNode * temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct TreeNode * insertNode(struct TreeNode * root, int data)
{
    if (root == NULL)
    {
        return newNode(data);
    }
    else
    {
        queue<struct TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            struct TreeNode * temp = q.front();
            q.pop();

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            else
            {
                temp->left = newNode(data);
                return root;
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
            else
            {
                temp->right = newNode(data);
                return root;
            }
        }

        return root;
    }
}

struct TreeNode * constructTree(struct TreeNode * root, struct ListNode * head)
{
    struct ListNode * temp = head;
    root = insertNode(root, temp->data);
    temp = temp->next;

    while (temp != NULL)
    {
        root = insertNode(root, temp->data);
        temp = temp->next;
    }

    return root;
}

void inorder(struct TreeNode * root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);

        return;
    }
}

void levelorder(struct TreeNode * root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        queue<struct TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            struct TreeNode * temp = q.front();
            cout<<temp->data<<" ";
            q.pop();

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }

        return;
    }
}


int main()
{
    struct ListNode * head = NULL;
    head = insertList(head, 10);
    insertList(head, 12);
    insertList(head, 15);
    insertList(head, 25);
    insertList(head, 30);
    insertList(head, 36);

    struct TreeNode * root = NULL;
    root = constructTree(root, head);

    inorder(root);
    cout<<"\n";
    levelorder(root);
    
    return 0;
}