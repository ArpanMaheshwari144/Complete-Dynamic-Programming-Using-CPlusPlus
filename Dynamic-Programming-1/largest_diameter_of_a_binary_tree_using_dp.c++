#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// General Syntax of Tree in Dynamic Programming
int heightOfBinaryTree(Node *root, int &result)
{
    // Base Condition
    if (root == NULL)
    {
        return 0;
    }

    // Hypothesis
    int l = heightOfBinaryTree(root->left, result);
    int r = heightOfBinaryTree(root->right, result);

    // Induction
    int tempAns = 1 + max(l, r);
    int ans = max(tempAns, 1 + l + r);
    result = max(result, ans);

    return tempAns;
}

// General Syntax of Tree in Dynamic Programming
int diameterOfBinaryTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = INT_MIN;
    heightOfBinaryTree(root, ans);
    return ans; // here we used nodes to count path length.
    // return ans - 1 //  here we used edges to count path length.
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Largest distance between two leafs is " << diameterOfBinaryTree(root);

    return 0;
}