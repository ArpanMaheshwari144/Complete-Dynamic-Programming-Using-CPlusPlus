#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->value = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int maxPathSumFromAnyLeafNodeToAnyLeafNode(Node *root, int &result)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->value;
    }

    int l = maxPathSumFromAnyLeafNodeToAnyLeafNode(root->left, result);
    int r = maxPathSumFromAnyLeafNodeToAnyLeafNode(root->right, result);

    if (root->left == NULL)
    {
        return r + root->value;
    }

    if (root->right == NULL)
    {
        return l + root->value;
    }

    int tempAns = max(l, r) + root->value;
    int ans = l + r + root->value;
    result = max(result, ans);

    return tempAns;
}

int maxPathSumFromAnyLeafNodeToAnyLeafNodeUtil(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = INT_MIN;
    maxPathSumFromAnyLeafNodeToAnyLeafNode(root, ans);
    return ans;
}

int main()
{
    Node *root = new Node(-15);
    root->left = new Node(5);
    root->right = new Node(6);
    root->left->left = new Node(-8);
    root->left->right = new Node(1);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(6);
    root->right->left = new Node(3);
    root->right->right = new Node(9);
    root->right->right->right = new Node(0);
    root->right->right->right->left = new Node(4);
    root->right->right->right->right = new Node(-1);
    root->right->right->right->right->left = new Node(10);

    cout << "Maximum path sum from any leaf node to any leaf node is " << maxPathSumFromAnyLeafNodeToAnyLeafNodeUtil(root);

    return 0;
}